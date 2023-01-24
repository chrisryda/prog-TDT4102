#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

// Her er en for-løkke gunstig, fordi vi får som input 
// hvor mange ganger noe skal gjøres fra starten av. 
void inputNIntegersAndPrintSumFor() {
    int n = 0;
    cout << "\nSkriv inn hvor mange tall du vil summere: ";
    cin >> n;

    int sum = 0;
    int temp = 0;
    for (int i = 1; i <= n; ++i) {
        cout << "Skriv inn heltall " << i << ": ";
        cin >> temp;
        sum += temp;
    }

    cout << "Summen av tallene: " << sum << "\n\n" << endl;
}

// Her er en while-løkke gunstig, fordi funksjonen skal
// gjøre noe frem til et krav er tilfredstilt (input == 0).
void inputNIntegersAndPrintSumWhile() {
    cout << "\nSkriv inn 0 for å avslutte summering og printe summen av tallene." << endl;
    int n;
    int i = 1;
    int sum = 0;
    while (n != 0) {
        cout << "Skriv inn heltall " << i << ": ";
        cin >> n;
        sum += n;
        ++i;
    }

    cout << "Summen av tallene: " << sum << "\n\n" << endl;
}

double inputDouble() {
    double x = 0;
    
    cout << "\nSkriv inn et desimaltall: ";
    cin >> x;
    return x;
}

void convertNOKtoEUR(double &nok) {
    if (nok < 0) {
        cout << "Skriv inn et positivt tall: ";
        cin >> nok;
        convertNOKtoEUR(nok);
    }

    nok = nok/9.75;
}

void printMultiplicationTable() {
    int height;
    int width;
    cout << "\nEnter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;

    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            cout << setw(4) << i*j;
        }
        cout << endl;
    }
    cout << "\n\n";
}

int main() {
    int choice = 100;
    while(choice != 0) {
        cout << "Velg funksjon:\n"
             << "0) Avslutt\n"
             << "1) Summer flere tall vha. for-loop\n"
             << "2) Summer flere tall vha. while-loop\n"
             << "3) Konverter NOK til EUR\n"
             << "4) Print et desimaltall\n"
             << "5) Print gangetabell\n"

             << "Angi valg (0-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                inputNIntegersAndPrintSumFor();
                break;  
            case 2:
                inputNIntegersAndPrintSumWhile();
                break;
            case 3:
            {
                // Brukte inputDouble() slik at det skal være mulig å skrive inn desimaltall slik
                // oppgaven ber om. Returtype double fordi jeg trenger verdien (ikke bare printe den)
                double number = inputDouble();
                convertNOKtoEUR(number);
                cout << "Dette tilsvarerer " << fixed << setprecision(2) << number << " euro\n\n" << endl;
                break;
            }
            case 4:
            {
                double number = inputDouble();
                cout << "Du skrev: " << number << "\n\n" << endl;
                break;
            }
            case 5:
                printMultiplicationTable();
                break;
            default:
                break;
                
        }
    }
    return 0;
}
