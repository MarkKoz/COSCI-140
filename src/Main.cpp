#include <iostream>
#include "Integers.h"

using namespace std;

int main() {
	char cont = 0;
	do {
		Integers integers(5);

		integers.setUserEntry();

		cout << "\nEnter [q/Q] to quit or any other character to input new "
				"integers: ";
		cin.get(cont); // Gets the first character.

		while (cin.get() != '\n') { // Ignores all following characters.
			// Assumes continue if > 1 char entered regardless of first char.
			cont = 0;
		}

		cout << '\n';
	} while (tolower(cont) != 'q');

	return 0;
}
