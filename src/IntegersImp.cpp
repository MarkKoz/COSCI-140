#include <iostream>
#include <string>
#include "Integers.h"

using namespace std;

Integers::Integers(int inputSize) {
	this->inputSize = inputSize;
	inputArray = new int[inputSize];

	// Why is this necessary if the program will never access the values of
	// the array before it has been filled with valid integers?
	for (int i = 0; i < inputSize; i++) {
		inputArray[i] = 0;
	}
}

Integers::~Integers() {
	delete [] inputArray;
}

void Integers::setUserEntry() {
	for (int i = 0; i < inputSize; i++) {
		string input;

		do {
			cout << "Enter integer " << i + 1 << ": ";
			getline(cin, input);
			cout << '\n';
		} while (!validate(input));

		inputArray[i] = stoi(input);
	}
}

bool Integers::validate(string input) {
	size_t length = input.length();

	if (input.empty()) {
		cout << "The input given is empty. Please try again.\n";

		return false;
	}

	for (int i = 0; i < length; i++) {
		char c = input[i];

		if ((i == 0 && c != '-' && !isdigit(c)) || (i != 0 && !isdigit(c))) {
			cout << "The input given is not an integer. Please try again.\n";

			return false;
		}
	}

	return true;
}

void Integers::displayIntegers() const {
	cout << "The integers inputted were: ";

	for (int i = 0; i < inputSize; i++) {
		cout << inputArray[i];

		if (i == inputSize - 1) {
			cout << '\n';
		} else {
			cout << ", ";
		}
	}
}

void Integers::getLargestSmallestIntegers() {
	int first = inputArray[0];
	int smallest = first;
	int largest = first;

	for (int i = 1; i < inputSize; i++) {
		int input = inputArray[i];

		if (input < smallest) {
			smallest = input;
		}

		if (input > largest) {
			largest = input;
		}
	}

	cout << "Smallest integer: " << smallest << '\n';
	cout << "Largest integer: " << largest << '\n';
}
