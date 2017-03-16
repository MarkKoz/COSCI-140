#ifndef CH11_QUIZ_INTEGERS_H
#define CH11_QUIZ_INTEGERS_H

#include <string>

using namespace std;

class Integers {
public:
	Integers(int inputSize);

	~Integers();

	void setUserEntry();

	bool validate(string input);

	void displayIntegers() const;

	void getLargestSmallestIntegers();

private:
	int inputSize;
	int* inputArray;
};

#endif
