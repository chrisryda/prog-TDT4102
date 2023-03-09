#pragma once
#include <iostream>
#include <utility>

class Dummy {
public:
    int *num;

    Dummy() {
        num = new int{0};
    }
    Dummy(const Dummy &other);
    
    ~Dummy() {
        delete num;
    }

    Dummy& operator=(Dummy rhs); 
};

void dummyTest();
