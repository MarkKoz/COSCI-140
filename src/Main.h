#ifndef CH11_QUIZ_MAIN_H
#define CH11_QUIZ_MAIN_H

#include <string>

using namespace std;

struct studentType;

void parseFile(string fileName, studentType** students, int &numStudents);

void writeFile(string fileName, studentType* students, int numStudents,
               int highestScore, studentType* highestStudents);

void setGrades(studentType* students, int numStudents);

#endif
