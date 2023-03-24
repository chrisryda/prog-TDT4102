#pragma once
#include "Person.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

enum class Campus { Trondheim, Alesund, Gjovik };
std::ostream& operator<<(std::ostream &os, const Campus &c);

class Meeting {
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;
public:
    Meeting(int day, int startTime, int endTime, Campus location, std::string subject, const std::shared_ptr<Person> leader);
    int getDay() const;    
    int getStartTime() const;    
    int getEndTime() const;
    Campus getLocation() const;    
    std::string getSubject() const;
    std::shared_ptr<Person> getLeader() const;
    std::vector<std::string> getParticipantList() const;
    void addParticipant(std::shared_ptr<Person> participant); 
    std::vector<std::shared_ptr<Person>> findPotentialCoDriving(Meeting m) const;
    std::string toString(); 
};

std::ostream& operator<<(std::ostream &os, const Meeting &m);
