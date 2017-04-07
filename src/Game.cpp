#include <cstring>
#include <iomanip>
#include <iostream>
#include "../include/Game.h"
#include "../include/Addition.h"
#include "../include/Subtraction.h"
#include "../include/Multiplication.h"
#include "../include/Division.h"

using namespace std;

/**
 * Constructor. Initialises user's statistics to default values.
 */
Game::Game() {
	userName = "";
	totalCorrect = 0;
	totalWrong = 0;
	totalWages = 0;
}

/**
 * Prints to console the title of the game and the author's name.
 */
void Game::splashScreen() {
	cout << "******************************************************************************\n"
	     << "*   _____ _           ___  ___      _   _       _____                        *\n"
	     << "*  |_   _| |          |  \\/  |     | | | |     |  __ \\                       *\n"
	     << "*    | | | |__   ___  | .  . | __ _| |_| |__   | |  \\/ __ _ _ __ ___   ___   *\n"
	     << "*    | | | '_ \\ / _ \\ | |\\/| |/ _` | __| '_ \\  | | __ / _` | '_ ` _ \\ / _ \\  *\n"
	     << "*    | | | | | |  __/ | |  | | (_| | |_| | | | | |_\\ \\ (_| | | | | | |  __/  *\n"
	     << "*    \\_/ |_| |_|\\___| \\_|  |_/\\__,_|\\__|_| |_|  \\____/\\__,_|_| |_| |_|\\___|  *\n"
	     << "*                                                                            *\n"
	     << "******************************************************************************\n"
         << "*.............................* By Mark Kozlov *.............................*\n"
         << "******************************************************************************\n";
}

/**
 * Displays a menu with the following choices and allows the user to make a
 * selection:
 *
 * 1. Addition Expression - displays an addition expression for the user to
 * solve.
 * 2. Subtraction Expression - displays a subtraction expression for the user
 * to solve.
 * 3. Multiplication Expression - displays a multiplication expression for
 * the user to solve.
 * 4. Division Expression - displays a division expression for the user to
 * solve.
 * 5. Statistics - displays the user's statistics
 * 6. Save & Quit - saves the users statistics to file and quits the game.
 */
void Game::menu() {
	cout << "==============================================================================\n"
         << "=--=         Choose an option from the right column and enter the         =--=\n"
         << "=--= corresponding character from the left column to make your selection. =--=\n"
         << "==============================================================================\n\n"
         << "==============================================================================\n"
         << "=------------------=    1      Addition Expression        =------------------=\n"
         << "=------------------=    2      Subtraction Expression     =------------------=\n"
         << "=------------------=    3      Multiplication Expression  =------------------=\n"
         << "=------------------=    4      Division Expression        =------------------=\n"
         << "=------------------=    5      Statistics                 =------------------=\n"
         << "=------------------=    q/Q    Save & Quit                =------------------=\n"
         << "==============================================================================\n\n";

	bool retry;
	char input;

	do {
		retry = false;

		cin.get(input); // Gets the first character.

		while (cin.get() != '\n') { // Ignores all following characters.
			// Assumes invalid if > 1 char entered regardless of first char.
			input = 0;
		}

		if (tolower(input) == 'q') {
			saveStats();
		} else if (input == '1') {
			Addition add = Addition();
			string answer;

			cout << add;
			getline(cin, answer);
			add.validate(answer);
			updateStats(add.checkAnswer());
			saveStats();
		} else if (input == '2') {
			Subtraction sub = Subtraction();
			string answer;

			cout << sub;
			getline(cin, answer);
			sub.validate(answer);
			updateStats(sub.checkAnswer());
			saveStats();
		} else if (input == '3') {
			Multiplication mult = Multiplication();
			string answer;

			cout << mult;
			getline(cin, answer);
			mult.validate(answer);
			updateStats(mult.checkAnswer());
			saveStats();
		} else if (input == '4') {
			Division div = Division();
			string answer;

			cout << div;
			getline(cin, answer);
			div.validate(answer);
			updateStats(div.checkAnswer());
			saveStats();
		} else if (input == '5') {
			displayStats();
		} else {
			cout << "That selection is invalid, please try again: ";
			retry = true;
		}
	} while (retry);
}

/**
 * Updates the total correct/wrong answers counter and the total
 * earnings statistics. Adds/deducts values as defined in the REWARD &
 * PENALTY constants, respectively.
 *
 * @param   correct     true if the user's answer was correct; false otherwise
 */
void Game::updateStats(bool correct) {
	if (correct) {
		++totalCorrect;
		totalWages += REWARD;
	} else {
		++totalWrong;
		totalWages -= PENALTY;
	}
}

/**
 * Prints to console the user's statistics (name, total correct, total wrong,
 * & total earnings).
 */
void Game::displayStats() {
	cout << "\nStatistics:\n\n";
    cout << "Name: " << userName << '\n';
    cout << "Correct: " << totalCorrect << '\n';
    cout << "Wrong: " << totalWrong << '\n';
	cout << "Earnings: " << setprecision(3) << totalWages << '\n';
}

/**
 * Prompts the user to enter a name and calls for it to be validated.
 *
 * Creates a statistics file with the given name if a statistics file with
 * the given name does not already exist. Instead, if the file exists, reads
 * the statistics from the file.
 */
void Game::requestName() {
	string name;
	string line;

	cout << "Enter your name: ";
	getline(cin, name);
	cout << '\n';
	validate(name);

	inData.open(name + ".txt");

	if (inData.fail()) {
		ofstream stream;

		stream.open(name + ".txt", ios::out | ios::trunc);

		stream << userName << '\n';
		stream << totalCorrect << '\n';
		stream << totalWrong << '\n';
		stream << setprecision(3) << totalWages << '\n';

		stream.close();
	} else {
		for (int i = 1; i <= 4; ++i) {
			getline(inData, line);

			// Does not validate. Assumes file has not been tampered with.
			switch (i) {
				case 1:
					userName = line;
					break;
				case 2:
					totalCorrect = stoi(line);
					break;
				case 3:
					totalWrong = stoi(line);
					break;
				case 4:
					totalWages = stod(line);
					break;
			}
		}

		inData.close();
	}
}

/**
 * Writes to file the user's statistics. Overwrites the previous content in
 * the file.
 */
void Game::saveStats() {
	outData.open(userName + ".txt", ios::out | ios::trunc);

	if (outData.fail()) {
		cout << "Error saving statistics to file.\n";
	} else {
		outData << userName << '\n';
		outData << totalCorrect << '\n';
		outData << totalWrong << '\n';
		outData << setprecision(3) << totalWages << '\n';

		outData.close();
	}
}

/**
 * Validates that the given string consists only of alphabetical characters.
 *
 * If valid, assigns the given string to the userName field. If invalid,
 * prompts the user for a new input until valid.
 *
 * @param   str1    the string to validate
 */
void Game::validate(string& str1) {
	bool isInvalid;

	do {
		isInvalid = false;

		if (str1 == "") {
			cout << "The str1 given is empty, please try again: ";
			getline(cin, str1);
			cout << '\n';

			isInvalid = true;
		}

		if (str1.find(" ") != string::npos && !isInvalid) {
			cout << "Spaces are not allowed, please try again: ";
			getline(cin, str1);
			cout << '\n';

			isInvalid = true;
		}

		for (int index = 0; index < str1.length() && !isInvalid; ++index) {
			if (!isalpha(str1[index])) {
				cout << "The str1 given contains invalid characters, "
						"please try again: ";
				getline(cin, str1);
				cout << '\n';

				isInvalid = true;
			}
		}
	} while (isInvalid);

	userName = str1;
}

