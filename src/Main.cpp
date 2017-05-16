#include <iostream>
#include "String.h"

/**
 * Compares two passed String objects against each other and prints to console
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
void strcmp(String& lvalue, String& rvalue, bool orEquals = false) {
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
	String last, first, age; // Default constructor.

	std::cout << "Enter your forename:\n";
	std::cin >> first; // Overloaded stream extraction operator.
	String::validateAlpha(first);

	std::cout << "Enter your surname:\n";
	std::cin >> last;
	String::validateAlpha(last);

	std::cout << "Enter your age in years:\n";
	std::cin >> age;
	String::validateDigit(age);

	// Overloaded stream insertion operator.
	std::cout << "Hello " << first << " " << last
	          << ". Your age is: " << age << " years.\n\n";

	String string1 = "abx"; // Overloaded constructor.
	String string2 = "ax";
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

	String arrNames[5]; // Array of String.

	std::cout << '\n';

	for (int i = 0; i < 5; ++i) {
		std::cout << "Enter name #" << i + 1 << ":\n";
		std::cin >> arrNames[i];
		String::validateAlpha(arrNames[i]);
	}

	std::cout << "The names you entered are:\n";

	for (int i = 0; i < 5; ++i) {
		std::cout << arrNames[i] << '\n';
	}

	string2 = "hello, ";
	String string3(string2); // Copy constructor.
	String string4 = string3 + "world";
	std::cout << '\n' << string4 << '\n';

	std::cout << "\nProgram complete.\n";
}


