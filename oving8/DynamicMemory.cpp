#include "DynamicMemory.h"
#include <iostream>
#include <cassert>


using namespace std;

void fillInFibonacciNumbers(int* result, int length) {
	assert(!(length < 2));
	*result = 0;
	*(result+1) = 1;
	for (int i = 2; i < length; i++) {
		*(result+i) = *(result+i-1) + *(result+i-2);
	}
}

void printArray(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		cout << *(arr+i) << endl;
	}
}

void createFibonacci() {
	int n = 0;
	cout << "How many Fibonacci numbers do you want to generate? Enter number: ";
	cin >> n;

	int *numbers = new int[n] {};
	fillInFibonacciNumbers(numbers, n);
	printArray(numbers, n);
	
	delete[] numbers;
	numbers = nullptr;
}
