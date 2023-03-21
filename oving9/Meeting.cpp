#include "Meeting.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

ostream& operator<<(std::ostream &os, const Campus &c) {
    switch (c) {
        case Campus::Trondheim:
            os << "Trondheim" << endl;
            break;
        case Campus::Alesund:
            os << "Ålesund" << endl;
            break;
        case Campus::Gjovik:
            os << "Gjøvik" << endl;
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
