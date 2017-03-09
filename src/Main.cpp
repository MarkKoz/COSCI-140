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

	parseFile("Data.txt", &students, numStudents);

	return 0;
}

void parseFile(string fileName, studentType** students, int &numStudents) {
	string line;
	int col = 0;
	ifstream stream;

	stream.open(fileName);

	if (stream.fail()) {
		cout << "\nError opening file '" << fileName << "'." << endl;
	} else {
		while (getline(stream, line, ' ')) {
			if (col == 0) {
				studentType* buffer = new studentType[numStudents];

				for (int i = 0; i < numStudents; i++) {
					buffer[i] = *students[i];
				}

				delete [] students;
				numStudents++;
				*students = new studentType[numStudents];

				for (int i = 0; i < numStudents - 1; i++) {
					*students[i] = buffer[i];
				}

				delete [] buffer;
				students[numStudents]->studentFName = line;
			} else if (col == 1) {
				students[numStudents]->studentLName = line;
			} else if (col == 2) {
				students[numStudents]->testScore = stoi(line);
				col = -1;
			}

			col++;
		}

		stream.close();
	}
}

void setGrade(studentType** students, int numStudents) {
	for (int i = 0; i < numStudents; i++) {
		int score = students[i]->testScore;
		char grade = 0;

		if (score >= 90) {
			grade = 'A';
		} else if (score >= 80) {
			grade = 'B';
		} else if (score >= 70) {
			grade = 'C';
		} else if (score >= 60) {
			grade = 'D';
		} else {
			grade = 'F';
		}

		students[i]->grade = grade;
	}
}
