#pragma once
#include <string>

class Animal {
protected:
    std::string name;
    int age;
public:
    Animal() {};
    Animal(std::string name, int age);
    virtual ~Animal() {};
    virtual std::string toString() = 0; // Hvprfor gjør dette klassen abstract?
};

class Dog : public Animal {
public:
    Dog(std::string name, int age);
    std::string toString();
};

class Cat : public Animal {
public:
    Cat(std::string name, int age);
    std::string toString();
};

void testAnimal();
