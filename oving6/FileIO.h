#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

void saveWordsToFile(std::experimental::filesystem::path fileName);
void saveFileToNewFile(std::ifstream input_file);
void countCharOccurancesInFile(std::ifstream input_file);
