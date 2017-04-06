#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/Division.h"

using namespace std;

Division::Division() {
	theAnswer = 0;
	userResponse = 0;

	randomize();
}

void Division::randomize() {
	num1 = rand() % 100 + 1; // 1-100

	do {
		num2 = rand() % 10 + 1; // 1-10
	} while (num1 % num2 != 0);

	theAnswer =  num1 / num2;
}

bool Division::checkAnswer() {
	bool isCorrect =  userResponse == theAnswer;

	cout << (isCorrect ? "Correct!\n" : "Wrong!\n");

	return isCorrect;
}

void Division::validate(string str1) {
	bool isInvalid;

	do {
		isInvalid = false;

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

		for (int i = 0; i < str1.length() && !isInvalid; ++i) {
			if (!isdigit(str1[i])) {
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

ostream& operator<<(ostream& stream, const Division& obj) {
	stream << obj.num1 << " / " << obj.num2 << " = ";

	return stream;
}