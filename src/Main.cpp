#include <cctype>
#include <cstring>
#include <iostream>
#include "Main.h"

using namespace std;

int main() {
	char cont = 0;

	do {
		char* input = getInput();
		delete [] input;

		cout << "\nEnter [q/Q] to quit or any other character to input a new "
				"sequence: ";
		cin.get(cont);

		while (cin.get() != '\n') { // Ignores all following characters.
			cont = 0; // Continues if > 1 char entered.
		}

		cout << endl;
	} while (tolower(cont) != 'q');

	return 0;
}

char* getInput() {
	cout << "Enter any sequence of characters: ";
	char c = cin.get();

	// TODO: Disallow whitespace as first character?
	while (isspace(c) && c != ' ') {
		cout << endl << "Nothing was entered. Please try again: ";
		cin.get(c);
	}

	char* input = new char[2] {c, '\0'};
	cin.get(c);

	while (c != '\n') {
		appendChar(c, &input);
		cin.get(c);
	}

/*	for (cin.get(c); c != '\n'; cin.get(c)) {
		appendChar(c, input);
	}*/

	return input;
}

void appendChar(char c, char** cstring) {
	size_t length = strlen(*cstring) + 1;

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

int* getCharFreq(char* cstring, char* chars) {
	size_t strLength = strlen(cstring);
	size_t charsLength = strlen(chars);
	int* freqs = new int[charsLength];

	// Initialises array with zeroes.
	for (int i = 0; i < charsLength; i++) {
		freqs[i] = 0;
	}

	for (int i = 0; i < charsLength; i++) {
		for (int j = 0; j < strLength; j++) {
			if (cstring[j] == chars[i]) {
				freqs[i]++;
			}
		}
	}

	return freqs;
}