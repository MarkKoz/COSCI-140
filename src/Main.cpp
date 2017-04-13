#include <cctype>
#include <iostream>
#include "../include/Game.h"

using namespace std;

int main() {
	Game game = Game();

	game.splashScreen();
	cout << '\n';
	game.requestName();

	char input;
	bool doCont;

	do {
		game.menu();

		cout << "\nEnter [q]/[q] to save and quit "
				"or any other key to continue: ";
		cin.get(input); // Gets the first character.

		while (cin.get() != '\n') { // Ignores all following characters.
			// Assumes continue if > 1 char entered regardless of first char.
			input = 0;
		}

		doCont = tolower(input) != 'q';

		cout << '\n';
	} while (doCont);

	return 0;
}
