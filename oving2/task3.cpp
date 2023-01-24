#include <iostream>
#include <math.h>

using namespace std;

double discriminant(double a, double b, double c) {
    return pow(b, 2) - 4*a*c;
}

void printRealRoots(double a, double b, double c) {
    double disc = discriminant(a, b, c);

    if (disc == 0) {
        double x = (-b + sqrt(disc))/(2*a);
        cout << "Solution: " << x << "\n\n" << endl;
        return;
    }
    else if (disc > 0) {
        double x1 = (-b + sqrt(disc))/(2*a);
        double x2 = (-b - sqrt(disc))/(2*a);
        cout << "Solutions: {" << x1 << ", " << x2 << "}" << "\n\n" << endl;
        return;
    } else {
        cout << "No real solutions for this equation.\n\n" << endl;
        return;
    }
}

void solveQuadraticEquation() {
    double a;
    double b;
    double c;
    cout << "\nValue of a: ";
    cin >> a;
    cout << "Value of b: ";
    cin >> b;
    cout << "Value of c: ";
    cin >> c;

    printRealRoots(a, b, c);
    return;
}

int main() {
    int choice = 100;
    while(choice != 0) {
        cout << "Choose action:\n"
             << "0) Exit\n"
             << "1) Solve quadratic equation\n"

             << "Action (0-1): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                solveQuadraticEquation();
                break;
            default:
                break;
                
        }
    }
    return 0;
}
