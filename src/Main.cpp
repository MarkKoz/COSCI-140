#include <cctype>
#include <cstring>
#include <iostream>
#include "Main.h"

using namespace std;

int main() {
	char* input = getInput();

	cout << "\nYour input is: ";

	for (int i = 0; *(input + i) != '\0'; i++) {
		cout << *(input + i);
	}

	cout << endl;

	return 0;
}

char* getInput() {
	char* input = nullptr;
	char c = 0;
	int length = 2;

	cout << "Enter any sequence of characters: ";
	cin.get(c);

	// TODO: Disallow whitespace as first character?
	while (isspace(c) && c != ' ') {
		cout << endl << "Nothing was entered. Please try again: ";
		cin.get(c);
	}

	input = new char[length] {c, '\0'};
	cin.get(c);

	while (c != '\n') {
		appendChar(c, &input, length);
		length++;
		cin.get(c);
	}

/*	for (cin.get(c); c != '\n'; length++, cin.get(c)) {
		appendChar(c, input, length);
	}*/

	return input;
}

void appendChar(char c, char** cstring, int length) {
	// Copies current string.
	char* buffer = new char[length];
	strcpy(buffer, *cstring);

	// Recreates string from copy with a size increase of 1.
	delete [] *cstring;
	*cstring = new char[length + 1];
	strncpy(*cstring, buffer, length - 1); // Doesn't copy NUL.
	delete [] buffer;

	// Puts next char into string and terminates it with NUL.
	*(*cstring + length - 1) = c;
	*(*cstring + length) = '\0';
}