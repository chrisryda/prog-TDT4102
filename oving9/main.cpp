#include "Car.h"
#include "Person.h"
#include "Meeting.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    Person p1{"Audust", "a@d.com"};
    cout << p1 << endl;

    Person p2{"Krisa", "c@d.com", make_unique<Car>(3)};
    cout << p2 << endl;

    Person p3{"T-bone", "t@b.com", make_unique<Car>(0)};
    cout << p3 << endl;

    shared_ptr<Person> p4 = make_shared<Person>("Ull", "wo@ol.com", make_unique<Car>(6));
    Meeting m{1, 14, 16, Campus::Trondheim, "TDT4102", p4};
    cout << m << endl;

    shared_ptr<Person> p5 = make_shared<Person>("G-wagon", "g@w.com", make_unique<Car>(1));
    cout << *p5.get() << endl;
    m.addParticipant(p5);
    cout << m << endl;

    return 0;
}
