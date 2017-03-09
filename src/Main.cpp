#include <iostream>
#include <fstream>
#include "Main.h"

struct studentType {
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

int main() {
	studentType* students = nullptr;
	int numStudents = 0;

	parseFile("Data.txt", &students, &numStudents);

	return 0;
}

void readFile(string fileName, string** lines, int* numLines) {
	string line;
	ifstream stream;

	stream.open(fileName);

	if (stream.fail()) {
		cout << "\nError opening file '" << fileName << "'." << endl;
	} else {
		while (getline(stream, line)) {
			string* buffer = new string[numLines];

			for (int i = 0; i < *numLines; i++) {
				buffer[i] = *lines[i];
			}

			delete [] lines;
			numLines++;
			*lines = new string[numLines];

			for (int i = 0; i < *numLines - 1; i++) {
				*lines[i] = buffer[i];
			}

			delete [] buffer;
			*lines[*numLines] = line;
		}
	}
}

void parseFile(string fileName, studentType** students, int* numStudents) {
	string* lines = nullptr;
	int numLines = 0;

	readFile(fileName, &lines, &numLines);

	for (int i = 0; i < numLines; i++) {
		*students[i];
	}
}