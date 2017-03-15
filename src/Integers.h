#ifndef CH11_QUIZ_INTEGERS_H
#define CH11_QUIZ_INTEGERS_H

class Integers {
public:
	int inputSize;
	int* inputArray;

	Integers(int& inputSize);

	~Integers();

	void setUserEntry();

	bool validate();

	void displayIntegers() const;

	void getLargestSmallestIntegers();
};

#endif
