#include "Utilities.h"

string toGreek(string sentence)
{
    // BEGIN: 2a

    for (size_t i = 0; i < sentence.size(); i++) {
        sentence[i] += 2;
    }
    return sentence;
    
    // END: 2a
}

vector<vector<string>> loadSvada()
{
    // BEGIN: 2b
    ifstream input_file{"SvadaWords.txt"};
    vector<vector<string>> categories;

    string line = "";
    vector<string> category{};
    while(std::getline(input_file, line)) {
        if (line == "||") {
            categories.emplace_back(category);
            category.clear();
            continue;
        }
        category.emplace_back(line);
    }
    categories.emplace_back(category);
    return categories;

    // END: 2b
}

string svadaGenerator(vector<vector<string>> svadaVec)
{
    // BEGIN: 2c1
    string res = "";

    std::random_device rd;
    std::default_random_engine generator(rd());
    for (auto category : svadaVec) {
        std::uniform_int_distribution<int> distribution(0, category.size()-1);
        res += category[distribution(generator)] + " ";
    }

    return res;
    // END: 2c1
}