#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "../include/Subtraction.h"

using namespace std;

/**
 * Constructor. Sets the answer fields to 0 and calls for an expression to be
 * randomly generated. Sets the seed based on the time for the the
 * pseudo-random number generator.
 */
Subtraction::Subtraction() {
	theAnswer = 0;
	userResponse = 0;

	srand(time(nullptr));
	randomize();
}

/**
 * Generates a division expression with a random minuend within the range
 * [1,10] and a random subtrahend between 1 and the value of the minuend so
 * that the difference is >= 0.
 *
 * Calculates the answer for the generated expression and assigns that value to
 * the theAnswer field.
 */
void Subtraction::randomize() {
	num1 = rand() % 10 + 1; // 1 to 10
	num2 = rand() % num1 + 1; // 1 to value of the minuend
	theAnswer = num1 - num2;
}

/**
 * Compares the user's answer to the actual answer to the expression. Prints
 * a message to console indicating whether or not the user's answer is correct.
 *
 * @return              true if the user's answer is correct; false otherwise
 */
bool Subtraction::checkAnswer() {
	bool isCorrect =  userResponse == theAnswer;

	cout << (isCorrect ? "Correct!\n" : "Wrong!\n");

	return isCorrect;
}

/**
 * Validates that the given string represents a positive integer >= 0.
 *
 * If valid, sets converts the string to an integer and assigns that value to
 * the userResponse field.. If invalid, prompts the user for a new input
 * until valid.
 *
 * @param   str1      the string to validate
 */
void Subtraction::validate(string str1) {
	bool isInvalid;

	do {
		isInvalid = false;

		if (str1 == "") {
			cout << "The answer given is empty, please try again: ";
			getline(cin, str1);
			cout << '\n';

			isInvalid = true;
		}

		if (str1.find(" ") != string::npos && !isInvalid) {
			cout << "Spaces are not allowed, please try again: ";
			getline(cin, str1);
			cout << '\n';

			isInvalid = true;
		}

		if (str1.find("-") != string::npos && !isInvalid) {
			cout << "All answers are POSITIVE integers, please try again: ";
			getline(cin, str1);
			cout << '\n';

			isInvalid = true;
		}

		for (int i = 0; i < str1.length() && !isInvalid; ++i) {
			if (!isdigit(str1[i])) {
				cout << "The answer given is not an integer, please try "
						"again: ";
				getline(cin, str1);
				cout << '\n';

				isInvalid = true;
			}
		}
	} while (isInvalid);

	userResponse = stoi(str1);
}

/**
 * Inserts into the stream the generated expression.
 */
ostream& operator<<(ostream& stream, const Subtraction& obj) {
	stream << obj.num1 << " - " << obj.num2 << " = ";

	return stream;
}
