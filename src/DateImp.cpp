#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

/**
 * Default constructor.
 */
Date::Date() {
	setYear(1900);
	setMonth(1);
	setDay(1);

	setNames();
	setDays();
}

/**
 * Overloaded constructor.
 *
 * @param   m       the month
 * @param   d       the day
 * @param   y       the year
 */
Date::Date(int m, int d, int y) {
	setNames();
	setDays();

	setMonth(m);
	setDay(d);
	setYear(y);
}

/**
 * Sets the month to the given integer.
 *
 * Validates the month to be in the range [1,NUM_MONTHS] but sets it
 * regardless of validity.
 *
 * @param   m       the month to set to
 * @return          true if the given month is valid; false otherwise
 */
bool Date::setMonth(int m) {
	month = m;

	return m >= 1 && m <= NUM_MONTHS;

}

/**
 * Sets the day to the given integer.
 *
 * Validates the day to be within the valid range of days for the month
 * corresponding to the current value of the month field. Sets it
 * regardless of validity.
 *
 * @param   d       the day to set to
 * @return          true if the given day is valid; false otherwise
 */
bool Date::setDay(int d) {
	day = d;

	return d <= numDays[month - 1];

}

/**
 * Sets the year to the given integer and updates the maximum number of days
 * for each month.
 *
 * Validates the year to be in the range [1900,9999] but sets it regardless
 * of validity.
 *
 * @param   y       the year to set to
 * @return          true if the given year is valid; false otherwise
 */
bool Date::setYear(int y) {
	year = y;
	setDays();

	return y >= 1900 && y <= 9999;

}

/**
 * Populates the names array with the names of the months.
 */
void Date::setNames() {
	names[0] = "January";
	names[1] = "February";
	names[2] = "March";
	names[3] = "April";
	names[4] = "May";
	names[5] = "June";
	names[6] = "July";
	names[7] = "August";
	names[8] = "September";
	names[9] = "October";
	names[10] = "November";
	names[11] = "December";
}

/**
 * Populates the numDays array with the number of days for each month.
 *
 * Accounts for leap year based the year corresponding to the current value
 * of the year field.
 */
void Date::setDays() {
	int adj = isLeapYear(year) ? 2 : 1; // Number of days to subtract from Feb.

	for (int m = 1; m <= NUM_MONTHS; ++m) {
		numDays[m - 1] = 30 + // Base. Formula below adds 1 or 0 to base.
		                 (m + (m / 8)) % 2 - // Reverses pattern at m >= 8.
		                 ((2 / m) * adj) + // Applies only to 1 <= m <= 2.
		                 ((1 / m) * adj * 2); // Applies only to m = 1.
	}
}

/**
 * Prints to console the date in the following format: %m/%d/%Y
 *
 * Example: 01/21/2001
 */
void Date::showDate1() {
	cout << month << "/" << day << "/" << year << '\n';
}

/**
 * Prints to console the date in the following format: %B %d, %Y
 *
 * Example: January 21, 2001
 */
void Date::showDate2() {
	cout << names[month - 1] << " " << day << ", " << year << '\n';
}

/**
 * Prints to console the date in the following format: %d %B, %Y
 *
 * Example: 21 January, 2001
 */
void Date::showDate3() {
	cout << day << " " << names[month - 1] << " " << year << '\n';
}

/**
 * Determines if the given year is a leap year.
 *
 * A year is a leap year if it is exactly divisible by 4 and not exactly
 * divisible by 100 (unless it is also exactly divisible by 400).
 *
 * @param   y       the year to be checked
 * @return          true if a leap year; false otherwise
 */
bool Date::isLeapYear(int y) {
	return y % 4 == 0 && (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0));
}

/**
 * Prefix increment operator (++).
 *
 * Increments the day by 1.
 *
 * Exits the program if the year of the resulting date is outside of the valid
 * range [1900,9999].
 *
 * @return          the new date after being incremented by 1 day
 */
Date Date::operator++() {
	int d = day + 1;
	int m = month;
	int y = year;

	if (d > numDays[month - 1]) {
		m = month + 1;
		d = 1;
	}

	if (m > NUM_MONTHS) {
		m = 1;
		y = year + 1;
	}

	if (!setYear(y)) {
		cout << "Year " << y << " is outside of the valid range [1900,9999]. "
				"Exiting program.\n";

		exit(EXIT_FAILURE);
	}

	setMonth(m);
	setDay(d);

	return *this;
}

/**
 * Postfix increment operator (++).
 *
 * Increments the day by 1.
 *
 * Exits the program if the year of the resulting date is outside of the valid
 * range [1900,9999].
 *
 * @return          the date before being incremented by 1 day
 */
Date Date::operator++(int) {
	Date temp = *this;

	int d = day + 1;
	int m = month;
	int y = year;

	if (d > numDays[month - 1]) {
		m = month + 1;
		d = 1;
	}

	if (m > NUM_MONTHS) {
		m = 1;
		y = year + 1;
	}

	if (!setYear(y)) {
		cout << "Year " << y << " is outside of the valid range [1900,9999]. "
				"Exiting program.\n";

		exit(EXIT_FAILURE);
	}

	setMonth(m);
	setDay(d);

	return temp;
}

/**
 * Prefix decrement operator (--).
 *
 * Decrements the day by 1.
 *
 * Exits the program if the year of the resulting date is outside of the valid
 * range [1900,9999].
 *
 * @return          the new date after being decremented by 1 day
 */
Date Date::operator--() {
	int d = day - 1;
	int m = month;
	int y = year;

	if (d < 1) {
		m = month - 1;
	}

	if (m < 1) {
		m = 12;
		y = year - 1;
	}

	if (!setYear(y)) {
		cout << "Year " << y << " is outside of the valid range [1900,9999]. "
				"Exiting program.\n";

		exit(EXIT_FAILURE);
	}

	if (d < 1) {
		d = numDays[m - 1];
	}

	setMonth(m);
	setDay(d);

	return *this;
}

/**
 * Prefix decrement operator (--).
 *
 * Decrements the day by 1.
 *
 * Exits the program if the year of the resulting date is outside of the valid
 * range [1900,9999].
 *
 * @return          the date before being decremented by 1 day
 */
Date Date::operator--(int) {
	Date temp = *this;

	int d = day - 1;
	int m = month;
	int y = year;

	if (d < 1) {
		m = month - 1;
	}

	if (m < 1) {
		m = 12;
		y = year - 1;
	}

	if (!setYear(y)) {
		cout << "Year " << y << " is outside of the valid range [1900,9999]. "
				"Exiting program.\n";

		exit(EXIT_FAILURE);
	}

	if (d < 1) {
		d = numDays[m - 1];
	}

	setMonth(m);
	setDay(d);

	return temp;
}

/**
 * Greater-than operator (>).
 *
 * Compares the value to the left of the operator to the value to the right
 * of the operator to check if the left value is greater than the right value.
 *
 * @return          true if left is greater than right; false otherwise
 */
bool Date::operator>(const Date& right) {
	return year > right.year
	       || (year == right.year && month > right.month)
	       || (year == right.year && month == right.month && day > right.day);
}

/**
 * Subtraction operator (-).
 *
 * Determines the number of days between two dates. Excludes the end date in
 * the calculation.
 *
 * @return          the number of days between two dates
 */
int Date::operator-(const Date& subtrahend) {
	int diff = 0;

	// Minuend
	int mY;
	int mM;
	int mD;
	int const* mDays;

	// Subtrahend
	int sY;
	int sM;
	int sD;
	int const* sDays;

	// Swaps minuend and subtrahend
	if (*this < subtrahend) {
		mY = subtrahend.year;
		mM = subtrahend.month;
		mD = subtrahend.day;
		mDays = subtrahend.numDays;

		sY = year;
		sM = month;
		sD = day;
		sDays = numDays;
	} else {
		mY = year;
		mM = month;
		mD = day;
		mDays = numDays;

		sY = subtrahend.year;
		sM = subtrahend.month;
		sD = subtrahend.day;
		sDays = subtrahend.numDays;
	}

	for (int y = sY + 1; y < mY; ++y) {
		isLeapYear(y) ? diff += 366 : diff += 365;
	}

	if (mY == sY) {
		// Adds days for full months between the subtrahend's and minuend's
		// months.
		for (int m = sM + 1; m < mM; ++m) {
			diff += mDays[m - 1];
		}
	} else {
		// Adds days for full months in the minuend's year.
		for (int m = 1; m < mM; ++m) {
			diff += mDays[m - 1];
		}

		// Adds days for full months in the subtrahends's year.
		for (int m = sM + 1; m <= NUM_MONTHS; ++m) {
			diff += sDays[m - 1];
		}
	}

	// Excludes day of end date.
	if (mY == sY && mM == sM) {
		diff += mD - sD;
	} else {
		diff += mD;
		diff += sDays[sM - 1] - sD;
	}

	return diff;
}

/**
 * Greater-than operator (<).
 *
 * Compares the value to the left of the operator to the value to the right
 * of the operator to check if the left value is less than the right value.
 *
 * @return          true if left is less than right; false otherwise
 */
bool Date::operator<(const Date& right) {
	return year < right.year
	       || (year == right.year && month < right.month)
	       || (year == right.year && month == right.month && day < right.day);
}

/**
 * Stream insertion operator (<<).
 *
 * Formats the date in the following format: %B %d, %Y
 *
 * Example: January 21, 2001
 *
 * @return          a stream with the formatted date
 */
ostream& operator<<(ostream& stream, const Date& date) {
	stream << date.names[date.month - 1] << " " << date.day << ", "
	       << date.year;

	return stream;
}

/**
 * Stream extraction operator (>>).
 *
 * Prompts the user to input a date and validates it. If valid, stores the
 * date into a Date object.
 *
 * @return          a stream with the inputted date
 */
istream& operator>>(istream& stream, Date& date) {
	bool isValid;

	do {
		string y;
		isValid = true;

		cout << "Enter the year as an integer [1900,9999]: ";
		stream >> y;

		if (y.empty()) {
			cout << "The input given is empty. Please try again.\n\n";

			isValid = false;
		}

		size_t length = y.length();

		for (int i = 0; isValid && i < length; ++i) {
			if (!isdigit(y[i])) {
				cout << "The input given is not an integer. "
						"Please try again.\n\n";

				isValid = false;
			}
		}

		if(isValid && !date.setYear(stoi(y))) {
			cout << "The year given is outside of the valid range. Please try "
					"again.\n\n";

			isValid = false;
		}
	} while (!isValid);

	cout << '\n';

	do {
		string m;
		isValid = true;

		cout << "Enter the month as an integer [1,12]: ";
		stream >> m;

		if (m.empty()) {
			cout << "The input given is empty. Please try again.\n\n";

			isValid = false;
		}

		size_t length = m.length();

		for (int i = 0; isValid && i < length; ++i) {
			if (!isdigit(m[i])) {
				cout << "The input given is not an integer. "
						"Please try again.\n\n";

				isValid = false;
			}
		}

		if(isValid && !date.setMonth(stoi(m))) {
			cout << "The month given is outside of the valid range. Please try "
					"again.\n\n";

			isValid = false;
		}
	} while (!isValid);

	cout << '\n';

	do {
		string d;
		isValid = true;

		cout << "Enter the day as an integer: ";
		stream >> d;

		if (d.empty()) {
			cout << "The input given is empty. Please try again.\n\n";

			isValid = false;
		}

		size_t length = d.length();

		for (int i = 0; isValid && i < length; ++i) {
			if (!isdigit(d[i])) {
				cout << "The input given is not an integer. "
						"Please try again.\n\n";

				isValid = false;
			}
		}

		if(isValid && !date.setDay(stoi(d))) {
			cout << "The day given is outside of the valid range. Please try "
					"again.\n\n";

			isValid = false;
		}
	} while (!isValid);

	cout << '\n';

	return stream;
}
