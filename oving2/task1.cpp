#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void inputAndPrintInteger() {
    int x = 0;
    
    cout << "\nSkriv inn et heltall: ";
    cin >> x;
    cout << "Du skrev inn: " << x << "\n\n" << endl;
}

int inputInteger() {
    int x = 0;
    
    cout << "\nSkriv inn et heltall: ";
    cin >> x;
    return x;
}

// Jeg valgte å benytte inputInteger() fordi oppgaven ba om at kun summen av tallene
// skulle printes, noe bruk av inputAndPrintInteger() ikke ville ført til.
void inputIntegersAndPrintSum() {
    int x = inputInteger();
    int y = inputInteger();
    cout << "Summen av tallene: " << x + y << "\n\n" << endl;
}

bool isOdd(int a) {
    return a%2 != 0;
}

void printHumanReadableTime(int seconds) {
    int minutes = (int) floor(seconds / 60) % 60;
    int hours = floor(seconds / 3600);

    cout << hours << " timer, " << minutes << " minutter og " << seconds % 60 << " sekunder\n\n" << endl; 
}

int main() {
    int choice = 100;
    while(choice != 0) {
        cout << "Velg funksjon:\n"
             << "0) Avslutt\n"
             << "1) Print et heltall\n"
             << "2) Print et heltall (på annet vis)\n"
             << "3) Summer to tall\n"
             << "4) Sjekk om et tall er odde\n"
             << "5) Omgjør sekunder til tidsformat\n"

             << "Angi valg (0-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                inputAndPrintInteger();
                break;
            case 2:
            {
                int number = inputInteger();
                cout << "Du skrev: " << number << "\n\n" << endl;
                break;
            }
            case 3:
                inputIntegersAndPrintSum();
                break;
            case 4:
            {
                cout << "\nSkriv inn et tall: ";
                int number;
                cin >> number;
                cout << (isOdd(number) ? "true\n\n" : "false\n\n");
                break;
            }
            case 5:
            {
                cout << "\nSkriv inn et tall: ";
                int number;
                cin >> number;
                printHumanReadableTime(number);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
