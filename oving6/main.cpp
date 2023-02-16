#include "FileIO.h"
#include "CourseCatalog.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

using namespace std;

int main() {
    // saveWordsToFile(std::experimental::filesystem::path{"../txt-files/fileIO.txt"});
    // saveFileToNewFile(std::ifstream{"../txt-files/fileToBeCopied.txt"});
    // countCharOccurancesInFile(std::ifstream{"../txt-files/grunnlov.txt"});
    CourseCatalog cc;
    // cc.saveToFile();
    cc.readFromFile(std::ifstream{"../txt-files/courseCatalog.txt"});
    cout << cc << endl;
    return 0;
}

// Oppgave 2b debuggeoppgave:
// Vi kan ikke bruke []-operatoren siden mapet er const,
// og []-operatoren potensielt kan legg til verdier
