#include <iostream>
#include <vector>
#include <iomanip>
#include "tests.h"
#include "utilities.h"

using namespace std;

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations;
    
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << " result: " << v0 << endl;
}

void testSwapNumbers() {
    int a = 5;
    int b = 77;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapNumbers(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
}

void testPrintStudent() {
    Student student {"Thomas Aquinas", "Philosophy", 48};
    printStudent(student);
}

void testIsInProgram() {
    Student student {"Thomas Aquinas", "Philosophy", 48};
    cout << isInProgram(student, "philosophy") << endl;
    cout << isInProgram(student, "elsys") << endl;
}

void testString() {
    string grades = randomizeString(8, 'A', 'F');
    double avg = 0;    
    vector<int> gradeCount(5);
    for (int i = gradeCount.size(); i >= 0; i--) {
        int count = countChar(grades, ('F'-i));
        gradeCount[i] = i*count;
    }
    for (size_t i = 0; i <= gradeCount.size(); i++) {
        avg += gradeCount[i];
    }
    cout << grades << endl;
    cout << "Avarage grade was " << setprecision(3) << avg/8 << endl;
}

void testReadInputToString() {
    string result = readInputToString(5, 'A', 'L');
    cout << "Result string: " << result << endl;
}

void testCountChar() {
    string test_str = "Hello, this is the string I want to use to test the function.";
    char c = 't';
    int count = countChar(test_str, c);
    cout << "Number of occurences of '" << c << "' in string was: " << count << endl; 
}
