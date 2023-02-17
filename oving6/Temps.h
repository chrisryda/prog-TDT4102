#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

struct Temps {
    double max;
    double min;
};
std::istream &operator>>(std::istream &is, Temps &t);
std::vector<Temps> readTemps(std::string file_name);
void tempStats(std::vector<Temps> temperatures);
