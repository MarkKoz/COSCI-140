#ifndef Subtraction_h
#define Subtraction_h

#include <iostream>
#include <string>

using namespace std;

class Subtraction {
	friend ostream& operator<<(ostream&, const Subtraction&);

public:
	Subtraction();
	void randomize();
	bool checkAnswer();
	void validate(string str1);

private:
	int num1; // Minuend
	int num2; // Subtrahend
	int theAnswer; // The answer to the expression.
	int userResponse; // The user's answer to the expression.
};

#endif
