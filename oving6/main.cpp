#include "FileIO.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

int main() {
    // saveWordsToFile(std::experimental::filesystem::path{"../txt-files/fileIO.txt"});
    // saveFileToNewFile(std::ifstream{"../txt-files/fileToBeCopied.txt"});
    countCharOccurancesInFile(std::ifstream{"../txt-files/grunnlov.txt"});
    return 0;
}

// Oppgave 2b debuggeoppgave:
// Vi kan ikke bruke []-operatoren siden mapet er const,
// og []-operatoren potensielt kan legg til verdier
