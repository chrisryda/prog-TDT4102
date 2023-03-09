#include "DynamicMemory.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
    createFibonacci();
    Matrix m{4, 2};
    Matrix m1{4};

    cout << m << endl;
    cout << m1 << endl;   
}