#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<string> vec) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << endl;
    }
}

void print_reverse(vector<string> vec) {
    for (vector<string>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++) {
        cout << *it << endl;
    }
}

void replace(vector<string> &vec, string old, string replacement) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        if (*it == old) {
            vec.erase(it);
            vec.insert(it, replacement);
        }
    }
}

int main() {
    vector<string> v{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
    print(v);
    print_reverse(v);
    replace(v, "Lorem", "Latin");
    print(v);
    return 0;
}
