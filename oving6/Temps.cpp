#include "Temps.h"

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

istream &operator>>(istream &is, Temps &t) {
    double max, min;
    is >> max >> min;
    t = {max, min};
    return is;
}

vector<Temps> readTemps(std::string file_name) {
    fs::path fn{file_name};
    ifstream input_file{fn};
    if (!input_file.good()) {
        throw std::invalid_argument("Invalid filname and/or path.");
    }

    Temps t;
    vector<Temps> temperatures;
    while (input_file >> t) {
        temperatures.emplace_back(t);
    }
    return temperatures;
}

void tempStats(vector<Temps> temperatures) {
    double max = 0;
    int max_index;
    double min = 0;
    int min_index;
    for (size_t i = 0; i < temperatures.size(); i++) {
        Temps t = temperatures[i];
        if (t.max > max) {
            max = t.max;
            max_index = i;
        }
        if (t.min < min) {
            min = t.min;
            min_index = i;
        }
    }
    cout << "Highest temperature was " << max << " at index " << max_index << endl; 
    cout << "Lowest temperature was " << min << " at index " << min_index << endl; 
}
