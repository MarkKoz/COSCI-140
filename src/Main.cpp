#include <iostream>
#include "myStringClass.h"

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

	// Overloaded relational operators (equals, less than, & greater than).
	if (string1 == string2) {
		std::cout << string1 << " = " << string2;
	} else if (string1 < string2) {
		std::cout << string1 << " < " << string2;
	} else {
		std::cout << string1 << " > " << string2;
	}
	std::cout << '\n';

	string1 = "axb";
	string2 = "aa";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 < string2) {
		std::cout << string1 << " < " << string2 << '\n';
	} else {
		std::cout << string1 << " > " << string2 << '\n';
	}

	string1 = "ab";
	string2 = "axb";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 < string2) {
		std::cout << string1 << " < " << string2 << '\n';
	} else {
		std::cout << string1 << " > " << string2 << '\n';
	}

	string1 = "ax";
	string2 = "aax";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 < string2) {
		std::cout << string1 << " < " << string2 << '\n';
	} else {
		std::cout << string1 << " > " << string2 << '\n';
	}

	string1 = "abcz";
	string2 = "abc";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 < string2) {
		std::cout << string1 << " < " << string2 << '\n';
	} else {
		std::cout << string1 << " > " << string2 << '\n';
	}

	string1 = "abc";
	string2 = "abcz";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 < string2) {
		std::cout << string1 << " < " << string2 << '\n';
	} else {
		std::cout << string1 << " > " << string2 << '\n';
	}

	string1 = "abc";
	string2 = "abc";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 < string2) {
		std::cout << string1 << " < " << string2 << '\n';
	} else {
		std::cout << string1 << " > " << string2 << '\n';
	}

	string1 = "abx";
	string2 = "ax";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 <= string2) {
		std::cout << string1 << " <= " << string2 << '\n';
	} else {
		std::cout << string1 << " >= " << string2 << '\n';
	}

	string1 = "axb";
	string2 = "aa";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 <= string2) {
		std::cout << string1 << " <= " << string2 << '\n';
	} else {
		std::cout << string1 << " >= " << string2 << '\n';
	}

	string1 = "ab";
	string2 = "axb";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 <= string2) {
		std::cout << string1 << " <= " << string2 << '\n';
	} else {
		std::cout << string1 << " >= " << string2 << '\n';
	}

	string1 = "ax";
	string2 = "aax";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 <= string2) {
		std::cout << string1 << " <= " << string2 << '\n';
	} else {
		std::cout << string1 << " >= " << string2 << '\n';
	}

	string1 = "abcz";
	string2 = "abc";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 <= string2) {
		std::cout << string1 << " <= " << string2 << '\n';
	} else {
		std::cout << string1 << " >= " << string2 << '\n';
	}

	string1 = "abc";
	string2 = "abcz";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 <= string2) {
		std::cout << string1 << " <= " << string2 << '\n';
	} else {
		std::cout << string1 << " >= " << string2 << '\n';
	}

	string1 = "abc";
	string2 = "abc";

	if (string1 == string2) {
		std::cout << string1 << " = " << string2 << '\n';
	} else if (string1 <= string2) {
		std::cout << string1 << " <= " << string2 << '\n';
	} else {
		std::cout << string1 << " >= " << string2 << '\n';
	}

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


