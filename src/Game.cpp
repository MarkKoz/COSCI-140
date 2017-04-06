#include <cstring>
#include <iomanip>
#include <iostream>
#include "../include/Game.h"
#include "../include/Addition.h"
#include "../include/Subtraction.h"
#include "../include/Multiplication.h"
#include "../include/Division.h"

using namespace std;

Game::Game() {
	userName = "";
	totalCorrect = 0;
	totalWrong = 0;
	totalWages = 0;
}

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

void Game::updateStats(bool correct) {
	if (correct) {
		++totalCorrect;
		totalWages += 0.05;
	} else {
		++totalWrong;
		totalWages -= 0.03;
	}
}

void Game::displayStats() {
	cout << "\nStatistics:\n\n";
    cout << "Name: " << userName << '\n';
    cout << "Correct: " << totalCorrect << '\n';
    cout << "Wrong: " << totalWrong << '\n';
	cout << "Earnings: " << setprecision(3) << totalWages << '\n';
}

void Game::requestName() {
	string name;

	cout << "Enter your name: ";
	getline(cin, name);
	cout << '\n';
	validate(name);

	fstream stream;
	string line;

	stream.open(name + ".txt");

	if (stream.fail()) {
		stream.open(name + ".txt", ios::in | ios::out | ios::trunc);

		stream << userName << '\n';
		stream << totalCorrect << '\n';
		stream << totalWrong << '\n';
		stream << setprecision(3) << totalWages << '\n';

		stream.close();
	} else {
		for (int i = 1; i <= 4; ++i) {
			getline(stream, line);

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

		stream.close();
	}
}

void Game::saveStats() {
	ofstream stream;

	stream.open(userName + ".txt", ios::out | ios::trunc);

	if (stream.fail()) {
		cout << "Error saving statistics to file.\n";
	} else {
		stream << userName << '\n';
		stream << totalCorrect << '\n';
		stream << totalWrong << '\n';
		stream << setprecision(3) << totalWages << '\n';

		stream.close();
	}
}

void Game::validate(string& str1) {
	bool isInvalid;

	do {
		isInvalid = false;

		if (str1 == "") {
			cout << "The name given is empty, please try again: ";
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
				cout << "The name given contains invalid characters, "
						"please try again: ";
				getline(cin, str1);
				cout << '\n';

				isInvalid = true;
			}
		}
	} while (isInvalid);

	userName = str1;
}

