#include <iostream>
#include <string>
#include "Integers.h"

using namespace std;

Integers::Integers(int inputSize) {
	this->inputSize = inputSize;
	inputArray = new int[inputSize];
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

	for (int i = 0; i < length; i++) {
		if (!isdigit(input[i])) {
			cout << "The input given is not an integer. Please try again.\n";

			return false;
		}
	}

	return true;
}

void Integers::displayIntegers() const {

}

void Integers::getLargestSmallestIntegers() {

}
