#include "Dummy.h"
#include <utility>

Dummy::Dummy(const Dummy &other) : num{ nullptr } {
    this->num = new int{};
    *num = *other.num;
}

Dummy &Dummy::operator=(Dummy rhs) {
    std::swap(num, rhs.num);
    return *this;
}

void dummyTest() {
    Dummy a;
    *a.num = 4;

    Dummy b{a};
    Dummy c;
    
    c = a;
    
    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';
    
    *b.num = 3;
    *c.num = 5;
    

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';
}
