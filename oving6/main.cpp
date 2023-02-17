#include "FileIO.h"
#include "CourseCatalog.h"
#include "Temps.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

int main() {
    saveWordsToFile(fs::path{"../txt-files/fileIO.txt"});
    saveFileToNewFile(ifstream{"../txt-files/fileToBeCopied.txt"});
    countCharOccurancesInFile(ifstream{"../txt-files/grunnlov.txt"});
    
    CourseCatalog cc;
    cc.readFromFile(std::ifstream{"../txt-files/courseCatalog.txt"});
    cc.addCourse("LIFE101", "Happiness");
    cc.saveToFile();

    vector<Temps> ts = readTemps("../txt-files/temperatures.txt");
    tempStats(ts);
    
    return 0;
}

// Oppgave 2b debuggeoppgave:
// Vi kan ikke bruke []-operatoren siden mapet er const,
// og []-operatoren potensielt kan legg til verdier
