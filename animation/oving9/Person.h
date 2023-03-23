#pragma once
#include "Car.h"
#include <string>
#include <memory>
#include <iostream>

class Person {
private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> car;
public:
    Person(std::string name, std::string email, std::unique_ptr<Car> c = nullptr);
    std::string getName() const;
    std::string getEmail() const;
    void setEmail(std::string newEmail);
    bool hasAvailableSeats() const;
    friend std::ostream& operator<<(std::ostream &os, const Person &p);
};
