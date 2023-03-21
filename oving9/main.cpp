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

    return 0;
}
