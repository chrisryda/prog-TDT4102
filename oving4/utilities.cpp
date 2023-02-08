#include <iostream>
#include <random>
#include "utilities.h"

using namespace std;

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printStudent(Student student) {
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Study program: " << student.studyProgram << endl;
}

bool isInProgram(Student student, string program) {
    string student_program(student.studyProgram);
    for (size_t i = 0; i < student_program.length(); i++) {
        student_program[i] = tolower(student.studyProgram[i]);       
    }
    for (size_t i = 0; i < program.length(); i++) {
        program[i] = tolower(program[i]);       
    }

    return student_program == program;
}

string randomizeString(int length, char lower, char upper) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(lower, upper);

    string res;
    for (int i = 0; i < length; i++) {
        res.push_back((char) distribution(generator));
    }
    return res;
}

string readInputToString(int length, char lower, char upper) {
    string res = "";
    string input;
    while (res.length() < (size_t) length) {
        cout << "Please enter input: ";
        cin >> input;
        if ((res + input).length() > (size_t) length) {
            cout << "Sorry, input was too long" << endl;
            continue;
        }
        for (size_t i = 0; i < input.length(); i++) {
            input[i] = tolower(input[i]);
            if (!isalpha(input[i]) || input[i] < tolower(lower) || input[i] > tolower(upper)) {
                cout << "Sorry, input must be between " << lower << " and " << upper << endl;
                input = "";
                break;
            }
        }
        res.append(input);
    }
    return res;
}

int countChar(string str, char c) {
    int count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (tolower(str[i]) == tolower(c)) {
            count++; 
        }
    }
    return count;
}
