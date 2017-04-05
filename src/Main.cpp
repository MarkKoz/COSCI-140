#include "../include/Game.h"

int main() {
	Game game = Game();

	game.splashScreen();
	cout << '\n';
	game.menu();

	return 0;
}
