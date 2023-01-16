#include <iostream>

using namespace std;

int maxOfTwo(int a, int b) {
    if (a > b) {
        cout << "A is greater than B" << endl;
        return a;
    } else {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << "Fiboncci numbers:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << i << " " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "-------" << endl;
    return b;
}

int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i = 1; i <= n; ++i) {
        totalSum += i*i;
        cout << i*i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc < n) {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
}

bool isPrime(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n) {
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)) {
            cout << i << " is a prime" << endl;
        }
    }
}

int findGreatestDivisor(int n) {
    for (int i = n-1; i > 0; --i) {
        if (n % i == 0) {
            return i;
        }
    }
}

int main() {
    cout << "Oppgave a)" << endl;
    cout << maxOfTwo(5,6) << endl;

    cout << "\nOppgave c)" << endl;
    cout << fibonacci(5) << endl;

    cout << "\nOppgave d)" << endl;
    cout << squareNumberSum(5) << endl;

    cout << "\nOppgave e)" << endl;
    triangleNumbersBelow(10);

    cout << "\nOppgave f) og g)" << endl;
    naivePrimeNumberSearch(14);

    cout << "\nOppgave h)" << endl;
    cout << findGreatestDivisor(14) << endl;
    cout << findGreatestDivisor(13) << endl;
}
