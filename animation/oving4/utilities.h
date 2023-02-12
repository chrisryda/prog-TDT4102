#pragma once

#include <string>

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes);

// Velger å bruke referanser, da ting blir mye mer tungvint  
// hvis funksjonen skal returnere de to nye tallene. 
void swapNumbers(int &a, int &b);

struct Student {
    std::string name;
    std::string studyProgram;
    int age;
};
void printStudent(Student student);
bool isInProgram(Student student, std::string studyProgram);

std::string randomizeString(int length, char lower, char upper);
std::string readInputToString(int length, char lower, char upper);
int countChar(std::string str, char c);
