#include <iostream>
#include "tests.h"
#include "mastermind.h"

using namespace std;

int main() {
    testCallByValue();
    testCallByReference();
    testSwapNumbers();
    testPrintStudent();
    testIsInProgram();
    testString();
    testReadInputToString();
    testCountChar();
    playMastermind(5, false);

    return 0;
}
