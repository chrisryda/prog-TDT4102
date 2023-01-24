#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

vector<int> calculateBalance(int deposit, int interest, int years) {
    vector<int> balance(years);
    for (int i = 0; i < years; i++) {
        balance[i] = deposit * pow((static_cast<double>(1) + static_cast<double>(interest)/100), i); 
    }

    return balance;
}

// Feilmeldingen betyr at operatoren << ikke godtar en vector
// som argument. Dette kan f.eks. løses ved overloading. 
void printBalance(vector<int> balance) {
    cout << "Year" << setw(8) << "Balance" << endl;  
    for (size_t i = 0; i < balance.size(); ++i) {
        cout << setw(2) << i << setw(8) << balance[i] << endl;
    }
}

// Feilen ligger i i <= v.size(), da dette burde vært kun
// mindre enn (<). Det forårsaker index out of range, som  
// compileren(?) oppdager, og dermed terminerer programmet  
// så vi ikke accesser data vi ikke skal accesse.
void funcWithError() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= v.size(); i++) {
        cout << v.at(i) << endl;
    }
}

int main() {
    vector<int> balance = calculateBalance(5000, 3, 3);
    printBalance(balance);
    // funcWithError();
    return 0;
}
