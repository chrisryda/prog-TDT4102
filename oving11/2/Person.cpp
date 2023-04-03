#include "Person.h"

using namespace std;

Person::Person(string firstName, string lastName) : firstName{firstName}, lastName{lastName} {}

string Person::getFirstName() const {
    return firstName;
}

string Person::getLastName() const {
    return lastName;
}

string Person::getFullName() const {
    return firstName + " " + lastName;
}

void Person::setFirstName(string newName) {
    firstName = newName;
}

void Person::setLastName(string newName) {
    lastName = newName;
}

ostream& operator<<(ostream &os, const Person &p) {
    os << p.firstName << " " << p.lastName << endl;
    return os;
}
