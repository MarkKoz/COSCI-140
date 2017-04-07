#ifndef Division_h
#define Division_h

#include <iostream>
#include <string>

using namespace std;

class Division {
	friend ostream& operator<<(ostream&, const Division&);

public:
	Division();
	void randomize();
	bool checkAnswer();
	void validate(string str1);

private:
	int num1; // Dividend
	int num2; // Divisor
	int theAnswer; // The answer to the expression.
	int userResponse; // The user's answer to the expression.
};

#endif
