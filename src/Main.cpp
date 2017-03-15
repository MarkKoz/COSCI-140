#include <iostream>
#include "Integers.h"

using namespace std;

int main() {
	char cont = 0;
	Integers integers(5);

	do {
		cout << "\nEnter [q/Q] to quit or any other character to input new "
				"integers: ";
		cin.get(cont);

		while (cin.get() != '\n') { // Ignores all following characters.
			cont = 0; // Continues if > 1 char entered.
		}

		cout << '\n';
	} while (tolower(cont) != 'q');

	return 0;
}
