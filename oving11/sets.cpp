#include <iostream>
#include <string>
#include <set>

using namespace std;

void print(set<string> s) {
    for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
}

void print_reverse(set<string> s) {
    for (set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << endl;
    }
}

void replace(set<string> &s, string old, string replacement) {
    for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
        if (*it == old) {
            s.erase(*it);
            s.insert(replacement);
        }
    }
}

int main() {
    set<string> s{"Absum", "Baptist", "Coroner", "Dolor", "Ezekiel", "Froci"};
    print(s);
    print_reverse(s);
    replace(s, "Absum", "Latin");
    print(s);
    return 0;
}
