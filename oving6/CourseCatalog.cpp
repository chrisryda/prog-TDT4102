#include "CourseCatalog.h"
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

CourseCatalog::CourseCatalog() {}

void CourseCatalog::addCourse(string code, string name) {
    code_name_map.insert({code, name});
}

void CourseCatalog::removeCourse(string code) {
    code_name_map.erase(code);
}

string CourseCatalog::getCourse(std::string code) {
    return code_name_map.at(code);
}

ostream &operator<<(ostream &os, const CourseCatalog &c) {
    os << "Subject code" << setw(20) << "Name" << endl;
    for(const auto &m : c.code_name_map){
        os << "  " << m.first << "     " << m.second << endl;
        // os << m.first << setw(20) << m.second << endl;
    }
    return os;
}

void CourseCatalog::saveToFile() {
    fs::path fileName{"../txt-files/courseCatalog.txt"};
    std::ofstream os{fileName};
    for(const auto &m : code_name_map){
        os << m.first << ";" << m.second << endl;
    }
}

void CourseCatalog::readFromFile(std::ifstream input_file) {
    if (!input_file.good()) {
        cout << "Invalid filname and/or path." << endl;
        return;
    }

    string line;
    while (std::getline(input_file, line)) {
        size_t split_index = line.find_first_of(';');
        string code = line.substr(0, split_index);
        string name = line.substr(split_index+1, line.size());
        code_name_map.insert({code, name});
    }
}
