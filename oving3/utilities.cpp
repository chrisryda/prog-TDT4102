#include <iostream>
#include <random>

using namespace std;

int randomWithLimits(int lower, int upper) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(lower, upper);

    return (int) distribution(generator);
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    if (abs(compareOperand - toOperand) <= maxError) {
        cout << name << " is valid.";
        return;
    } else {
        cout << name << " is not valid: Expected " << toOperand << ", but got " << compareOperand << "." << endl;
        return;
    }
}

// Problemet med funksjonen er at den 
// ikke tar høyde for at error != 0
// bool checkIfDistanceToTargetIsCorrect() {
//     double error = targetPractice(0,0,0);
//     if(error == 0) return true;
// }
