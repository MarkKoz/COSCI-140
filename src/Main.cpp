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
 * @param   input       the user's input string
 * @param   sizeVar     the variable in which to store the user's input as an
 *                      integer
 */
void validateInt(string input, int& sizeVar);

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
 * @param   arr     the array of whose contents to display
 * @param   size    the size of the array
 */
void displayArray(int* arr, int size);

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
	string input;
	int size;

	cout << "Enter the amount of integers to generate (>= 0): ";

	do {
		getline(cin, input);
		validateInt(input, size);
	} while (size == -1);

	int* array = makeArray(size);

	cout << endl;
	loadNumberData(array, size);
	displayArray(array, size);
	selectionSort(array, size);
	displayArray(array, size);

	//TODO: Format numbers?
	cout << "\nAverage: " << average(array, size) << "\n";
	cout << "Median: " << median(array, size) << "\n";
	cout << "Mode: " << mode(array, size) << endl;
}

void validateInt(string input, int& sizeVar) {
	sizeVar = -2;

	if (input.empty()) {
		cout << "The input given is empty. Please try again: ";
		sizeVar = -1;
	} else if (input.find(" ") != string::npos) {
		cout << "Spaces are not allowed. Please try again: ";
		sizeVar = -1;
	} else {
		size_t length = input.length();

		// Iterates through every character in the input string and checks if
		// it's a digit.
		for (int index = 0; index < length && sizeVar != -1; index++) {
			if (!isdigit(input[index])) {
				cout << "The selection is not an integer greater than or "
						"equal to 0. Please try again: ";
				sizeVar = -1;
			}
		}
	}

	if (sizeVar != -1) {
		sizeVar = stoi(input);
	}
}

int* makeArray(int size) {
	return new int[size];
}

void loadNumberData(int* arr, int size) {
	int* arrEndPtr = &arr[size];

	srand(time(nullptr));

	while (arr < arrEndPtr) {
		*arr = rand() % 100 + 1;
		arr++;
	}
}

void displayArray(int* arr, int size) {
	int* arrEndPtr = &arr[size];

	while (arr < arrEndPtr) {
		if (arr == arrEndPtr - 1) {
			cout << *arr << endl;
		} else {
			cout << *arr << ", ";
		}

		arr++;
	}
}

void selectionSort(int arr[], int size) {
	int iMin;

	for (int iToSort = 0; iToSort < size - 1; iToSort++) {
		iMin = iToSort;

		for (int iUnsorted = iToSort + 1; iUnsorted < size; iUnsorted++) {
			if (arr[iUnsorted] < arr[iMin]) {
				iMin = iUnsorted;
			}
		}

		int buffer = arr[iToSort];
		arr[iToSort] = arr[iMin];
		arr[iMin] = buffer;
	}
}

double average(int* arr, int size) {
	int* arrEndPtr = &arr[size];
	double total;

	while (arr < arrEndPtr) {
		total += *arr;
		arr++;
	}

	return total / size;
}

double median(int* arr, int size) {
	return 0;
}

int mode(int* arr, int size) {
	// TODO: Handle cases of multiple values with the same frequency?
	return -1;
}