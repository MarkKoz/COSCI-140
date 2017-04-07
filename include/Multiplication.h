#ifndef Multiplication_h
#define Multiplication_h

#include <iostream>
#include <string>

using namespace std;

class Multiplication {
	friend ostream& operator<<(ostream&, const Multiplication&);

public:
	Multiplication();
	void randomize();
	bool checkAnswer();
	void validate(string str1);;

private:
	int num1; // Multiplicand
	int num2; // Multiplier
	int theAnswer; // The answer to the expression.
	int userResponse; // The user's answer to the expression.
};

#endif
