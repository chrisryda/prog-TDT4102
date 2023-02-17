#include "FileIO.h"
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

void saveWordsToFile(fs::path fileName) {
    cout << "Please write a word that you wish to save to file and press enter." << endl;
    cout << "When finished, type 'quit'\n" << endl;

    string word;
    std::ofstream output_stream{fileName};
    while (true) {
        cout << "Enter word: ";
        cin >> word;
        if (word == "quit") {break;}
        output_stream << word << endl;
    }
}

void saveFileToNewFile(std::ifstream input_file) {
    if (!input_file.good()) {
        cout << "Invalid filname and/or path." << endl;
        return;
    }
    fs::path file_name{"../txt-files/copiedFile.txt"};
    std::ofstream output_stream{file_name};

    int i = 1;
    string line;
    while (std::getline(input_file, line)) {
        output_stream << i << ": " << line << endl;
        i++;
    }
}

void countCharOccurancesInFile(std::ifstream input_file) {
    if (!input_file.good()) {
        cout << "Invalid filname and/or path." << endl;
        return;
    }
    map<char, int> char_occ_map{
        {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0},
        {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0},
        {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
        {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0},
        {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
        {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
        {'y', 0}, {'z', 0},
    };
    
    char c;
    while (input_file >> c) {
        if (tolower(c) == 'æ' || tolower(c) == 'ø' || tolower(c) == 'å') {
            continue;
        }
        if (isalpha(c)) {
            char_occ_map.at(tolower(c))++;
        }
    }

    for(const auto& m : char_occ_map){
        cout << m.first << ": " << m.second << endl;
    }
}
