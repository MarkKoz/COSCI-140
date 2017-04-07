#ifndef Game_h
#define Game_h

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Game {
public:
	Game();
	void splashScreen();
	void menu();
	void updateStats(bool correct);
	void displayStats();
	void requestName();
	void saveStats();
	void validate(string& str1);

private:
	string userName; // User's name statistic.
	double totalWages; // User's total earnings statistic.
	int totalCorrect; // Users' total correct answers statistic.
	int totalWrong; // User's total wrong answers statistic.
	const double REWARD = 0.05; // The amount to reward for a correct answer.
	const double PENALTY = 0.03; // The amount to deduct for a wrong answer.
	ofstream outData; // Output file stream.
	ifstream inData; // Input file stream.
};

#endif
