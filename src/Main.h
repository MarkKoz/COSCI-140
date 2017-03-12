#ifndef CH11_QUIZ_MAIN_H
#define CH11_QUIZ_MAIN_H

#include <string>

using namespace std;

struct studentType;

int getHighestScore(studentType** students, int numStudents);

void getStudentsWithScore(int score, studentType** students, int numStudents,
                          studentType*** out, int& outSize);

bool parseFile(string fileName, studentType*** students, int &numStudents);

bool writeFile(string fileName, studentType** students, int numStudents,
               int scoreHighest, studentType** studentsHighest, int
               numStudentsHighest);

void setGrades(studentType** students, int numStudents);

void expandArray(studentType*** array, int &size, int increment);

#endif
