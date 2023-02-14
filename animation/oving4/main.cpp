#include "std_lib_facilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"

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
    playMastermindVisual(5, false);

    return 0;
}
