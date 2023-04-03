#include "Person.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

// Non case-sensitive compare-algorithm for Person-objects
// Comparing is done by their full names
bool compare(const Person& one, const Person& two) {
  int i = 0;
  string first = one.getFullName();
  string second = two.getFullName();

  while ((i < first.length()) && (i < second.length())) {
    if (tolower(first[i]) < tolower(second[i])) {
        return true;
    } else if (tolower(first[i]) > tolower(second[i])) {
        return false;
    } 
    ++i;
  }
  return (first.length() < second.length());
}

void insertOrdered(list<Person> &l, const Person& p) {
    l.push_back(p);
    l.sort(compare);
}

int main() {
    list<Person> l;
    Person p1{"Molly", "Dahlin"};
    Person p2{"Abakus", "Bek"};
    Person p3{"Marieke", "Ovrumbo"};
    Person p4{"Yonas", "Wright"};
    Person p5{"Mohammed", "Dalern"};
    Person p6{"Christine", "Estsumus"};
    insertOrdered(l, p1);
    insertOrdered(l, p2);
    insertOrdered(l, p3);
    insertOrdered(l, p4);
    insertOrdered(l, p5);
    insertOrdered(l, p6);

    for (Person p : l) {
        cout << p << endl;
    }
    
    return 0;
}
