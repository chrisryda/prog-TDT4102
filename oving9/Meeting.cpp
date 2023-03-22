#include "Meeting.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

ostream& operator<<(std::ostream &os, const Campus &c) {
    switch (c) {
        case Campus::Trondheim:
            os << "Trondheim";
            break;
        case Campus::Alesund:
            os << "Ålesund";
            break;
        case Campus::Gjovik:
            os << "Gjøvik";
            break;
    }
    return os;
}

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, const shared_ptr<Person> leader) 
    : day{day}, startTime{startTime}, endTime{endTime}, location{location}, subject{subject}, leader{leader} 
    {
        participants.emplace_back(leader);
    }

int Meeting::getDay() const {
    return day;
}

int Meeting::getStartTime() const {
    return startTime;
}

int Meeting::getEndTime() const {
    return endTime;
}

Campus Meeting::getLocation() const {
    return location;
}

string Meeting::getSubject() const {
    return subject;
}

shared_ptr<Person> Meeting::getLeader() const {
    return leader;
}

vector<string> Meeting::getParticipantList() const {
    vector<string> par;
    for (auto &p : participants) {
        par.emplace_back(p.get()->getName());
    }
    return par;
}

void Meeting::addParticipant(shared_ptr<Person> participant) {
    participants.emplace_back(participant);
}

vector<shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting m) {
    vector<shared_ptr<Person>> potentialCoDrivers;
    for (auto &p : m.participants) {
        if (
            m.day == this->day &&
            m.location == this->location &&
            p.get()->hasAvailableSeats() &&
            abs(m.startTime - this->startTime) < 1 &&
            abs(m.endTime - this->endTime) < 1
        ) 
        {
            potentialCoDrivers.emplace_back(p);
        }
    }

    return potentialCoDrivers;
}

ostream& operator<<(std::ostream &os, const Meeting &m) {
    os << "\nMeeting:" << endl;
    os << "Subject: " << m.getSubject() << endl;
    os << "Location: " << m.getLocation() << endl;
    os << "Start time: " << m.getStartTime() << endl;
    os << "End time: " << m.getEndTime() << endl;
    os << "Meeting leader: " << m.getLeader().get()->getName() << endl;
    os << "Participants:" << endl;
    for (string s : m.getParticipantList()) {
        os << s << endl;
    }

    return os;
}
