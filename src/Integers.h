#ifndef CH11_QUIZ_INTEGERS_H
#define CH11_QUIZ_INTEGERS_H

#include <string>

using namespace std;

class Integers {
public:
	int inputSize;
	int* inputArray;

	Integers(int inputSize);

	~Integers();

	void setUserEntry();

	bool validate(string input);

	void displayIntegers() const;

	void getLargestSmallestIntegers();
};

#endif
