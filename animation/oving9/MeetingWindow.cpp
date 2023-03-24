#include "MeetingWindow.h"
#include "widgets/TextInput.h"
#include "widgets/DropdownList.h"
#include "widgets/Button.h"
#include "AnimationWindow.h"
#include "Meeting.h"
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

vector<string> locationOptions = {"Trondheim", "Gjovik", "Alesund"};
vector<string> meetingLeaderOptions{""};

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const string& title) 
    : AnimationWindow(x, y, w, h, title),
    quitBtn{{quitBtnX, quitBtnY}, btnW, btnH, "Quit"},
    createMeetingBtn{{quitBtnX, quitBtnY+50}, btnW, btnH, "Create meeting"},
    createPersonBtn{{quitBtnX, quitBtnY+100}, btnW, btnH, "Create person"},
    
    personName{{leftSidePersonFieldsX, leftFieldOneY}, fieldW, fieldH, ""},
    personEmail{{leftSidePersonFieldsX, leftFieldTwoY}, fieldW, fieldH, ""},
    personSeats{{leftSidePersonFieldsX, leftFieldThreeY}, fieldW, fieldH, ""},
    personNewBtn{{leftSidePersonFieldsX, leftFieldFourY}, btnW, btnH, "Add person"},
    personData{{personDataX, personDataY}, fieldW+100, fieldH+250, ""},
    
    meetingNewBtn{{leftSideMeetingFieldsX, leftFieldOneY}, btnW, btnH, "Add meeting"},
    meetingSubject{{leftSideMeetingFieldsX, leftFieldTwoY}, fieldW, fieldH, ""},
    meetingDay{{leftSideMeetingFieldsX, leftFieldThreeY}, fieldW, fieldH, ""},
    meetingStart{{leftSideMeetingFieldsX, leftFieldFourY}, fieldW, fieldH, ""},
    meetingEnd{{leftSideMeetingFieldsX, leftFieldFiveY}, fieldW, fieldH, ""},
    meetingLocation{{leftSideMeetingFieldsX, leftFieldSixY}, fieldW, fieldH, locationOptions},
    meetingLeader{{leftSideMeetingFieldsX, leftFieldSevenY}, fieldW, fieldH, meetingLeaderOptions},
    meetingData{{meetingDataX, personDataY}, fieldW+100, fieldH+250, ""}
{
    add(quitBtn);
    add(createMeetingBtn);
    add(createPersonBtn);

    add(personName);
    add(personEmail);
    add(personSeats);
    add(personData);
    add(personNewBtn);

    add(meetingSubject);
    add(meetingDay);
    add(meetingStart);
    add(meetingEnd);
    add(meetingLocation);
    add(meetingLeader);
    add(meetingNewBtn);
    add(meetingData);

    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
    createMeetingBtn.setCallback(std::bind(&MeetingWindow::cb_meetings, this));
    createPersonBtn.setCallback(std::bind(&MeetingWindow::cb_persons, this));
    personNewBtn.setCallback(std::bind(&MeetingWindow::cb_addPerson, this));
    meetingNewBtn.setCallback(std::bind(&MeetingWindow::cb_addMeeting, this));

    showPersonPage();
}

void MeetingWindow::cb_quit() {
    this->close();
}

void MeetingWindow::cb_addPerson() {
    newPerson();
}

void MeetingWindow::cb_addMeeting() {
    newMeeting();
}

void MeetingWindow::cb_persons() {
    showPersonPage();
}

void MeetingWindow::cb_meetings() {
    showMeetingPage();
}

void MeetingWindow::showPersonPage() {
    meetingSubject.setVisible(false);
    meetingDay.setVisible(false);
    meetingStart.setVisible(false);
    meetingEnd.setVisible(false);
    meetingLocation.setVisible(false);
    meetingLeader.setVisible(false);
    meetingNewBtn.setVisible(false);

    personNewBtn.setVisible(true);
    personName.setVisible(true);
    personEmail.setVisible(true);
    personSeats.setVisible(true);
}

void MeetingWindow::showMeetingPage() {
    personNewBtn.setVisible(false);
    personName.setVisible(false);
    personEmail.setVisible(false);
    personSeats.setVisible(false);

    meetingSubject.setVisible(true);
    meetingDay.setVisible(true);
    meetingStart.setVisible(true);
    meetingEnd.setVisible(true);
    meetingLocation.setVisible(true);
    meetingLeader.setVisible(true);
    meetingNewBtn.setVisible(true);
}

void MeetingWindow::newPerson() {
    string name = personName.getText();
    string email = personEmail.getText();
    int numOfSeats = stoi(personSeats.getText());
    if(
        name.empty() || 
        email.empty() ||
        name.find_first_not_of(' ') == std::string::npos ||
        email.find_first_not_of(' ') == std::string::npos
    ) 
    {
        cout << "Invalid input" << endl;
        this->close();
    }
    if (numOfSeats > 0) {
        people.emplace_back(new Person{name, email, make_unique<Car>(numOfSeats-1)});
    } else {
        people.emplace_back(new Person{name, email});
    }
    meetingLeaderOptions.emplace_back(name);
    meetingLeader.setOptions(meetingLeaderOptions);
    personName.setText("");
    personEmail.setText("");
    personSeats.setText("");
    updatePeopleDisplay();
}

void MeetingWindow::updatePeopleDisplay() {
    string peeps = "----People----\n";
    for (shared_ptr<Person> p : people) {
        peeps += (p.get()->getName()) + "\n";
    }
    personData.setText(peeps);
}

void MeetingWindow::newMeeting() {
    string subject = meetingSubject.getText();
    int day = stoi(meetingDay.getText());
    int startTime = stoi(meetingStart.getText());
    int endTime = stoi(meetingEnd.getText());
    string location = meetingLocation.getValue();
    string leader = meetingLeader.getValue();
    if(
        subject.empty() || 
        location.empty() ||
        leader.empty() ||
        subject.find_first_not_of(' ') == std::string::npos ||
        location.find_first_not_of(' ') == std::string::npos ||
        leader.find_first_not_of(' ') == std::string::npos ||
        day < 0 ||
        startTime <= 0 ||
        endTime <=0 ||
        endTime <= startTime
    ) 
    {
        cout << "Invalid input" << endl;
        this->close();
    }

    Campus c;
    if (location == "Trondheim") {
        c = Campus::Trondheim;
    } else if (location == "Gjovik") {
        c = Campus::Gjovik;
    } else {
        c = Campus::Alesund;
    }

    for (shared_ptr<Person> p : people) {
        if (p.get()->getName() == leader) {
            meetings.emplace_back(new Meeting{day, startTime, endTime, c, subject, p});
            break;
        }
    }
    
    meetingSubject.setText("");
    meetingDay.setText("");
    meetingStart.setText("");
    meetingEnd.setText("");
    updateMeetingDisplay();
}

void MeetingWindow::updateMeetingDisplay() {
    string meets = "----Meetings----\n";
    for (auto &m : meetings) {
        meets += m.get()->toString();
    }
    meetingData.setText(meets);
}
