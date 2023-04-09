#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <algorithm>

template<typename T>
T maximum(T a, T b) {
    if (a > b) { return a; }
    return b;
}

template<typename T>
void shuffle(std::vector<T> &v) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, (v.size()-1));

    for (int i = 0; i < 1000; i++) {
        std::swap(v[distribution(generator)], v[distribution(generator)]);
    }
}

int main() {
    int a = 1;
    int b = 2;
    int c = maximum(a, b);

    double d = 2.4;
    double e = 3.2;
    double f = maximum(d,e);

    std::vector<int> g{1, 2, 3, 4, 5, 6, 7};
    shuffle(g);

    std::vector<double> h{1.2, 2.2, 3.2, 4.2};
    shuffle(h);
    
    std::vector<std::string> i{"one", "two", "three", "four"};
    shuffle(i);

    return 0;
}
