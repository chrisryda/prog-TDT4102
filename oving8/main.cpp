#include "DynamicMemory.h"
#include "Dummy.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
    // createFibonacci();
    // dummyTest(); 
    Matrix A{2};
    A.set(0, 0, 1.0);
    A.set(0, 1, 2.0);
    A.set(1, 0, 3.0);
    A.set(1, 1, 4.0);
    
    Matrix B{2};
    B.set(0, 0, 4.0);
    B.set(0, 1, 3.0);
    B.set(1, 0, 2.0);
    B.set(1, 1, 1.0);
    
    Matrix C{2};
    C.set(0, 0, 1.0);
    C.set(0, 1, 3.0);
    C.set(1, 0, 1.5);
    C.set(1, 1, 2.0);

    cout << A << "\n" << B << "\n" << C << endl;
    A += B + C;
    cout << "----After addition-----\n" << endl;
    cout << A << "\n" << B << "\n" << C << endl;
}
