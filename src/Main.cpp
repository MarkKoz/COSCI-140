#include <iostream>
#include "myStringClass.h"

/**
 * Compares two given String objects against eachother and prints to console
 * the results.
 *
 * By default, comparisons are made using operators ==, <, and >. However, if
 * optional parameter orEquals is true, ==, <=, and >= are used instead.
 *
 * @param   lvalue      the String object to be on the left side of the
 *                      comparison
 * @param   rvalue      the String object to be on the right side of the
 *                      comparison
 * @param   orEquals    if < and > comparisons should be <= and >=
 */
void strcmp(myStringClass& lvalue,
            myStringClass& rvalue,
            bool orEquals = false) {
	// Overloaded relational operators.
	if (!orEquals) {
		if (lvalue == rvalue) {
			std::cout << lvalue << " = " << rvalue << '\n';
		} else if (lvalue < rvalue) {
			std::cout << lvalue << " < " << rvalue << '\n';
		} else {
			std::cout << lvalue << " > " << rvalue << '\n';
		}
	} else {
		if (lvalue == rvalue) {
			std::cout << lvalue << " = " << rvalue << '\n';
		} else if (lvalue <= rvalue) {
			std::cout << lvalue << " <= " << rvalue << '\n';
		} else {
			std::cout << lvalue << " >= " << rvalue << '\n';
		}
	}
}

int main() {
	myStringClass last, first, age; // Default constructor.

	std::cout << "Enter your first name only\n";
	std::cin >> first; // Overloaded stream extraction operator.
	myStringClass::validateUserInput(first);

	std::cout << "what is your last name?\n";
	std::cin >> last;
	myStringClass::validateUserInput(last);

	std::cout << "enter your age\n";
	std::cin >> age;
	myStringClass::validateUserInt(age);

	// Overloaded stream insertion operator.
	std::cout << "hello " << first << " " << last << ", age: " << age << '\n';

	myStringClass string1 = "abx"; // Overloaded constructor.
	myStringClass string2 = "ax";
	strcmp(string1, string2);
	strcmp(string1, string2, true);

	string1 = "axb";
	string2 = "aa";
	strcmp(string1, string2);
	strcmp(string1, string2, true);

	string1 = "ab";
	string2 = "axb";
	strcmp(string1, string2);
	strcmp(string1, string2, true);

	string1 = "ax";
	string2 = "aax";
	strcmp(string1, string2);
	strcmp(string1, string2, true);

	string1 = "abcz";
	string2 = "abc";
	strcmp(string1, string2);
	strcmp(string1, string2, true);

	string1 = "abc";
	string2 = "abcz";
	strcmp(string1, string2);
	strcmp(string1, string2, true);

	string1 = "abc";
	string2 = "abc";
	strcmp(string1, string2);
	strcmp(string1, string2, true);

	myStringClass arrayOfNames[5]; // Array of myStringClass.

	for (int x = 0; x < 5; x++) {
		std::cout << "enter name " << x + 1 << '\n';
		std::cin >> arrayOfNames[x];
		myStringClass::validateUserInput(arrayOfNames[x]);
	}

	std::cout << "The names you entered are:\n";

	for (int x = 0; x < 5; x++) {
		std::cout << arrayOfNames[x] << '\n';
	}

	string2 = "Hello ";
	myStringClass string3(string2); // Copy constructor.
	myStringClass string4 = string3 + "World";

	std::cout << string4 << '\n';

	std::cout << "Good-bye\n";
	system("pause");

	return 0;
}


