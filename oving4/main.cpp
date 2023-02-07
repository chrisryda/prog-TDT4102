#include <iostream>
#include "tests.h"
#include "mastermind.h"

using namespace std;

int main() {
    int choice = 100;
    while(choice != 0) {
        cout << "\nChoose action:\n"
             << "0) Exit\n"
             << "1) Test callByValue()\n"
             << "2) Test callByReference()\n"
             << "3) Test swapNumbers()\n"
             << "4) Test printStudent()\n"
             << "5) Test isInProgram()\n"
             << "6) Test testString()\n"
             << "7) Test readInputToString()\n"
             << "8) Test countChar()\n"
             << "9) Test playMastermind()()\n"

             << "Choose option (0-9): ";
        cin >> choice;
        cout << "\n\n" << endl;
        switch (choice) {
            case 1:
                testCallByValue();
                break;
            case 2:
                testCallByReference();
                break;
            case 3:
                testSwapNumbers();
                break;
            case 4:
                testPrintStudent();
                break;
            case 5:
                testIsInProgram();
                break;
            case 6:
                testString();
                break;
            case 7:
                testReadInputToString();
                break;
            case 8:
                testCountChar();
                break;
            case 9:
                playMastermind(5);
                break;
            default:
                break;
        }
    }
    return 0;
}
