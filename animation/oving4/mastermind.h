#pragma once

#include <string>
#include <vector>

void playMastermind(int n, bool hide_code);
int checkCharactersAndPosition(std::string code, std::string guess);
int checkCharacters(std::string code, std::string guess);
std::vector<int> getFeedback(std::string code, std::string guess);
