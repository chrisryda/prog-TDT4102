#include "Animal.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

Animal::Animal(string _name, int _age) {
    name = _name;
    age = _age;
};

Dog::Dog(string _name, int _age) : Animal(_name, _age) {};

string Dog::toString() {
    return "Dog: " + name + ", " + to_string(age);
}

Cat::Cat(string _name, int _age) : Animal(_name, _age) {};

string Cat::toString() {
    return "Cat: " + name + ", " + to_string(age);
}

void testAnimal() {
    vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Purre", 15));
    animals.emplace_back(new Dog("Molly", 9));

    for (auto &a : animals) {
        cout << a->toString() << endl;
    }
}
