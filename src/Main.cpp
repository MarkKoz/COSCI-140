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
	cout << endl;
	displayArray(array, size);

	// TODO: Format numbers?
	cout << "\nAverage: " << average(array, size) << "\n";
	cout << "Median: " << median(array, size) << "\n";
	cout << "Mode: " << mode(array, size) << endl;

	delete [] array; // Redundant since the program ends right after anyway...
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
	double total = 0;

	while (arr < arrEndPtr) {
		total += *arr;
		arr++;
	}

	return total / size;
}

double median(int* arr, int size) {
	if (size % 2 != 0) { // odd
		return arr[(size - 1) / 2];
	} else { // even
		int iMin = (size / 2) - 1; // Index of the lesser median
		int valMin = arr[iMin]; // Value of the lesser median
		double diff = arr[iMin + 1] - valMin; // Difference between medians

		return valMin + (diff / 2);
	}
}

int mode(int* arr, int size) {
	// TODO: Handle cases of multiple values with the same frequency?
	int* arrEndPtr = &arr[size];
	int* maxPtr = nullptr;
	int maxFreq = 0;

	while (arr < arrEndPtr) {
		int* search = arr;
		int freq = 1;

		// Finds how many following elements have the same value.
		while (*(search + 1) == *search) {
			freq++;
			search++;
		}

		if (freq > maxFreq) {
			maxPtr = arr;
			maxFreq = freq;
		}

		// Next iteration will start at the first element with a value not
		// equal to the value of the last searched element.
		arr += freq;
	}

	return maxFreq <= 1 ? -1 : *maxPtr;
}