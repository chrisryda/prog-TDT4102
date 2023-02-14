#pragma once
#include <string>

void playMastermind(int n, bool hide_code);
int checkCharactersAndPosition(std::string code, std::string guess);
int checkCharacters(std::string code, std::string guess);
