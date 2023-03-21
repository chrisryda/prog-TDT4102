#include "Person.h"
#include "Car.h"
#include <string>
#include <memory>
#include <iostream>

using namespace std;

Person::Person(string name, string email, unique_ptr<Car> c) : name{name}, email{email} {
    car = move(c);
}

string Person::getName() const {
    return name;
}

string Person::getEmail() const {
    return email;
}

void Person::setEmail(std::string newEmail) {
    email = newEmail;
}

bool Person::hasAvailableSeats() const {
    return (car.get() != nullptr && car.get()->hasFreeSeats());
}

ostream& operator<<(ostream &os, const Person &p) {
    os << "\nPerson" << endl;
    os << "Name: " << p.name << endl;
    os << "Email: " << p.email << endl;
    string hasAvailableSeats = p.hasAvailableSeats() ? "Yes" : "No";
    os << "Has available seats: " << hasAvailableSeats << endl;

    return os;
}
