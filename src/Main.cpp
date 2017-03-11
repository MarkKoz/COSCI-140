#include <iostream>
#include <fstream>
#include <iomanip>
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
	setGrades(students, numStudents);

	int scoreHighest = getHighestScore(students, numStudents);
	studentType* studentsHighest = nullptr;
	int numStudentsHighest = 0;

	getStudentsWithScore(scoreHighest, students, numStudents,
	                     &studentsHighest, numStudentsHighest);
	writeFile("Out.txt", students, numStudents, scoreHighest,
	          studentsHighest, numStudentsHighest);

	return 0;
}

int getHighestScore(studentType* students, int numStudents) {
	int highestScore = 0;

	for (int i = 0; i < numStudents; i++) {
		int studentScore = students[i].testScore;

		if (studentScore > highestScore) {
			highestScore = studentScore;
		}
	}

	return highestScore;
}

void getStudentsWithScore(int score, studentType* students, int numStudents,
                          studentType** out, int& outSize) {

	for (int i = 0; i < numStudents; i++) {
		studentType student = students[i];

		if (student.testScore == score) {
			expandArray(out, outSize, 1);
			*out[outSize] = student;
		}
	}
}

void parseFile(string fileName, studentType** students, int& numStudents) {
	string line;
	int col = 0;
	ifstream stream;

	stream.open(fileName, ios::in);

	if (stream.fail()) {
		cout << "\nError opening file '" << fileName << "'.\n";
	} else {
		while (getline(stream, line, ' ')) {
			if (col == 0) {
				expandArray(students, numStudents, 1);
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

void writeFile(string fileName, studentType* students, int numStudents,
               int scoreHighest, studentType* studentsHighest, int
               numStudentsHighest) {
	ofstream stream;

	stream.open(fileName, ios::out);

	if (stream.fail()) {
		cout << "\nError creating file '" << fileName << "'.\n";
	} else {
		cout << left << setw(28) << "Student Name";
		cout << right << setw(12) << "Test Score";
		cout << setw(8) << "Grade\n";

		for (int i = 0; i < numStudents; i++) {
			studentType student = students[i];
			string name = student.studentFName + ", " + student.studentLName;

			cout << left << setw(28) << name;
			cout << right << setw(12) << student.testScore;
			cout << setw(8) << student.grade << '\n';
		}

		cout << "\nHighest Test Score:" << scoreHighest << '\n';
		cout << "Students having the highest test score:\n";

		for (int i = 0; i < numStudentsHighest; i++) {
			studentType student = studentsHighest[i];
			string name = student.studentFName + ", " + student.studentLName;

			cout << left << setw(28) << name;
		}

		stream.close();
	}
}

void setGrades(studentType* students, int numStudents) {
	for (int i = 0; i < numStudents; i++) {
		int score = students[i].testScore;
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

		students[i].grade = grade;
	}
}

// Would use a template, but it doesn't really matter since this function is
// only used for arrays of type studentType.
void expandArray(studentType** array, int& size, int increment) {
	studentType* buffer = new studentType[size];

	for (int i = 0; i < size; i++) {
		buffer[i] = *array[i];
	}

	delete [] array;
	size += increment;
	*array = new studentType[size];

	for (int i = 0; i < size - 1; i++) {
		*array[i] = buffer[i];
	}

	delete [] buffer;
}
