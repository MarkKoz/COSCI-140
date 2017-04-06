#include "../include/Game.h"

int main() {
	Game game = Game();

	game.splashScreen();
	cout << '\n';
	game.requestName();
	game.menu();

	char input;
	bool doCont;

	do {
		cout << "\nEnter [q]/[q] to save and quit "
				"or any other key to continue: ";
		cin.get(input); // Gets the first character.

		while (cin.get() != '\n') { // Ignores all following characters.
			// Assumes invalid if > 1 char entered regardless of first char.
			input = 0;
		}

		doCont = tolower(input) != 'q';

		if (doCont) {
			cout << '\n';
			game.menu();
		}
	} while (doCont);

	return 0;
}
