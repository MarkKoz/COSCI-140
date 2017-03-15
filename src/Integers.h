#ifndef CH11_QUIZ_INTEGERS_H
#define CH11_QUIZ_INTEGERS_H

class Integers {
public:
	int inputSize = 5;
	int inputArray[];

	Integers(int inputSize);

	void setUserEntry();

	bool validate();

	void displayIntegers() const;

	void getLargestSmallestIntegers();
};

#endif
