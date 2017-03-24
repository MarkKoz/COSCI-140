#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date;
const int NUM_MONTHS = 12;

class Date {
public:
	// Constructors
	Date();
	Date(int, int, int);

	// Mutators
	bool setMonth(int m);
	bool setDay(int d);
	bool setYear(int y);

	// Other member functions
	void showDate1();
	void showDate2();
	void showDate3();
	bool isLeapYear(int);

	// Overloaded operators
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	bool operator>(const Date&);
	int operator-(const Date&);
	bool operator<(const Date&);
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);

private:
	int month;
	int day;
	int year;

	// Holds the names of the months.
	string names[NUM_MONTHS];

	// Holds the number of days that each month has.
	int numDays[NUM_MONTHS];

	// Assigns the month names to the names array.
	void setNames();

	// Assigns the numbers of days to the numDays array.
	void setDays();
};

#endif
