#ifndef Addition_h
#define Addition_h

#include <iostream>
#include <string>

using namespace std;

class Addition {
	friend ostream& operator<<(ostream&, const Addition&);

public:
	Addition();
	void randomize();
	bool checkAnswer();
	void validate(string str1);

private:
	int num1; // Augend
	int num2; // Addend
	int theAnswer; // The answer to the expression.
	int userResponse; // The user's answer to the expression.
};

#endif
