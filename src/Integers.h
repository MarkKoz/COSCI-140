#ifndef CH11_QUIZ_INTEGERS_H
#define CH11_QUIZ_INTEGERS_H

#include <string>

using namespace std;

class Integers {
public:
	/**
	 * Constructor. Sets the size variable for the array of inputs.
	 * Creates an array of that size and initialises all elements to 0.
	 *
	 * @param   inputSize   the size of the array of inputs
	 */
	Integers(int inputSize);

	/**
	 * Destructor. Destroys the array of inputs.
	 */
	~Integers();

	/**
	 * Prompts the user for inputs, calls for each one to be validated, and
	 * stores each one in an array. Prompts the user again for an input if
	 * the one entered was invalid.
	 */
	void setUserEntry();

	/**
	 * Validates a given string to be an integer. If negative, the negative
	 * sign ('-') must be the first character in the input and have no spaces
	 * between it and the digits. If invalid, prints a message to the console
	 * indicating an invalid input.
	 *
	 * @param   input   the user input as a string to be validated
	 * @return          true if valid, false otherwise
	 */
	bool validate(string input);

	/**
	 * Prints to console a comma-delimited list of every integer in the array
	 * of inputs..
	 */
	void displayIntegers() const;

	/**
	 * Calculates and prints to console the smallest and largest integers out of
	 * the set in the array of inputs.
	 */
	void getLargestSmallestIntegers();

private:
	int inputSize;
	int* inputArray;
};

#endif
