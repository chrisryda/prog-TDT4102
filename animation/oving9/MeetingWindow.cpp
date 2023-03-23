#include "MeetingWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "AnimationWindow.h"
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const string& title) 
    : AnimationWindow(x, y, w, h, title),
    quitBtn{{quitBtnX, quitBtnY}, btnW, btnH, "Quit"},
    personNewBtn{{personNewBtnX, personNewBtnY}, btnW, btnH, "Add person"},
    personName{{personNameX, personNameY}, fieldW, fieldH, ""},
    personEmail{{personEmailX, personEmailY}, fieldW, fieldH, ""}
{
    add(personName);
    add(personEmail);
    add(personNewBtn);
    add(quitBtn);
    personNewBtn.setCallback(std::bind(&MeetingWindow::cb_addPerson, this));
    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
}

void MeetingWindow::printPeople() {
    cout << "\n----People----";
    for (shared_ptr<Person> p : people) {
        cout << *p.get(); 
    }
} 

void MeetingWindow::cb_quit() {
    this->close();
}

void MeetingWindow::cb_addPerson() {
    newPerson();
}

void MeetingWindow::newPerson() {
    string name = personName.getText();
    string email = personEmail.getText();
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
    people.emplace_back(new Person{name, email});
    personName.setText("");
    personEmail.setText("");
}
