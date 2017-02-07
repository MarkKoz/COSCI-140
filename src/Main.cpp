#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/******************************************************************************
* Declarations
******************************************************************************/

/**
 * Ensures that the user's input is an integer >= 0.
 *
 * @param   userIn      the user's input string
 * @param   userInput   the variable in which to store the user's input as an
 *                      integer
 */
void validateInt(string userIn, int& userInput);

/**
 * Dynamically allocates an array of type int and returns a pointer to it.
 *
 * @param   size    the size of the array to be created
 * @return          a pointer to the array created
 */
int* makeArray(int size);

/**
 * Loads a given array with integers of random values, ranging from 1
 * to 100.
 *
 * Uses pointer arithmetic to step through the array.
 *
 * @param   arr     the array into which to load numbers
 * @param   size    the size of the array
 */
void loadNumberData(int* arr, int size);

/**
 * Prints the contents of a given array to the console.
 *
 * Uses pointer arithmetic to step through the array.
 *
 * @param   numberData          the array of whose contents to display
 * @param   qtyOfRandomNumbers  the size of the array
 */
void displayArray(int* numberData, int qtyOfRandomNumbers);

/**
 * Sorts the contents of a given array into ascending order by means of a
 * selection sort algorithm.
 *
 * @param   arr     the array to sort
 * @param   size    the size of the array
 */
void selectionSort(int arr[], int size);

/**
 * Calculates and returns the average of the values in a given array.
 *
 * @param   arr     the array for which to calculate the average
 * @param   size    the size of the array
 * @return          the average
 */
double average(int* arr, int size);

/**
 * Calculates and returns the median of the values in a given array.
 *
 * @param   arr     the array for which to calculate the median
 * @param   size    the size of the array
 * @return          the average
 */
double median(int* arr, int size);

/**
 * Calculates and returns the mode (the value which appears most frequently) of
 * the values in a given array.
 *
 * Returns -1 if no value appears more than once.
 *
 * @param   arr     the array for which to calculate the mode
 * @param   size    the size of the array
 * @return          the average
 */
int mode(int* arr, int size);

/******************************************************************************
* Definitions
******************************************************************************/

int main() {
	string inputStr;
	int inputInt;

	cout << "Enter the amount of integers to generate: ";

	do {
		cin >> inputStr;
		validateInt(inputStr, inputInt);
	} while (inputInt == -1);
}

void validateInt(string userIn, int& userInput) {
	userInput = -2;

	if (userIn.empty()) {
		cout << "The input given is empty. Please try again: ";
		userInput = -1;
	} else if (userIn.find(" ") != string::npos) {
		cout << "Spaces are not allowed. Please try again: ";
		userInput = -1;
	} else {
		size_t length = userIn.length();

		// Iterates through every character in the input string and checks if
		// it's a digit.
		for (int index = 0; index < length && userInput != -1; index++) {
			if (!isdigit(userIn[index])) {
				cout << "The selection is not an integer greater than or "
						"equal to 0. Please try again: ";
				userInput = -1;
			}
		}
	}

	if (userInput != -1) {
		userInput = stoi(userIn);
	}
}

int* makeArray(int size) {
	return new int[size];
}

void loadNumberData(int* arr, int size) {
	srand(time(nullptr));

	while (arr < &arr[size]) {
		*arr = rand();
		arr++;
	}
}

void displayArray(int* numberData, int qtyOfRandomNumbers) {
	while (numberData < &numberData[qtyOfRandomNumbers]) {
		cout << *numberData;
		numberData++;
	}

	cout << endl;
}

void selectionSort(int arr[], int size) {

}

double average(int* arr, int size) {
	return 0;
}

double median(int* arr, int size) {
	return 0;
}

int mode(int* arr, int size) {
	// TODO: Handle cases of multiple values with the same frequency?
	return -1;
}