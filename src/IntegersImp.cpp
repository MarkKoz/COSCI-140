#include "Integers.h"

Integers::Integers(int& inputSize) {
	this->inputSize = inputSize;
	inputArray = new int[inputSize];
}

Integers::~Integers() {
	delete [] inputArray;
}

void Integers::setUserEntry() {

}

bool Integers::validate() {
	return false;
}

void Integers::displayIntegers() const {

}

void Integers::getLargestSmallestIntegers() {

}
