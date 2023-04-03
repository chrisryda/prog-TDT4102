#pragma once
#include <string>
#include <list>
#include <iostream>

class Person 
{
private:
    std::string firstName;
    std::string lastName;
public:
    Person(std::string firstName, std::string lastName);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    void setFirstName(std::string newName);
    void setLastName(std::string newName);
    friend std::ostream& operator<<(std::ostream &os, const Person &p);
};
