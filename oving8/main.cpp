#include "DynamicMemory.h"
#include "Dummy.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
    createFibonacci();
    
    Matrix m{4, 2};
    Matrix m1{4};
    Matrix b{m};
    Matrix c = m1;

    cout << m << endl;
    cout << m1 << endl;
    cout << b << endl;
    cout << c << endl;

    dummyTest(); 
}
