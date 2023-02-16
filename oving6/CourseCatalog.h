#pragma once

#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <experimental/filesystem>

class CourseCatalog{
private:
    std::map<std::string, std::string> code_name_map;
public:
    CourseCatalog();
    void addCourse(std::string code, std::string name);
    void removeCourse(std::string code);
    std::string getCourse(std::string code);
    friend std::ostream &operator<<(std::ostream &os, const CourseCatalog &c);
    void saveToFile();
    void readFromFile(std::ifstream input_file);
};
