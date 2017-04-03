#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/Addition.h"

using namespace std;

Addition::Addition() {
	theAnswer = 0;
	userResponse = 0;

	randomize();
}

void Addition::randomize() {
	num1 = rand() % 10 + 1; // 1 to 10
	num2 = rand() % 10 + 1; // 1 to 10
	theAnswer = num1 + num2;
}

bool Addition::checkAnswer() {
	bool isCorrect =  userResponse == theAnswer;

	cout << (isCorrect ? "Correct!\n" : "Wrong!\n");

	return isCorrect;
}

void Addition::validate(string str1) {
	bool isInvalid = false;

	do {
		if (str1 == "") {
			cout << "The answer given is empty, please try again: ";
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

		if (str1.find("-") != string::npos && !isInvalid) {
			cout << "All answers are POSITIVE integers, please try again: ";
			getline(cin, str1);
			cout << '\n';

			isInvalid = true;
		}

		for (int index = 0; index < str1.length() && !isInvalid; index++) {
			if (!isdigit(str1[index])) {
				cout << "The answer given is not an integer, please try "
						"again: ";
				getline(cin, str1);
				cout << '\n';

				isInvalid = true;
			}
		}
	} while (isInvalid);

	userResponse = stoi(str1);
}

ostream& operator<<(ostream& stream, const Addition& obj) {
	stream << num1 << " + " << num2 << " = ";

	return stream;
}
