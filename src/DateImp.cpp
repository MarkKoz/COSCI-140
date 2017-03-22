#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

/******************************************************************************
 Constructors
 ******************************************************************************/

/**
 * Default constructor.
 */
Date::Date() {
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

/******************************************************************************
 Mutators
 ******************************************************************************/

/**
 * Sets the month to the given integer.
 *
 * Validates the month to be in the range [1,NUM_MONTHS].
 *
 * @param   m       the month to set to
 * @return          true if the given month is valid, false otherwise
 */
bool Date::setMonth(int m) {
	if (m >= 1 && m <= NUM_MONTHS) {
		month = m;

		return true;
	}

	return false;
}

/**
 * Sets the day to the given integer.
 *
 * Validates the day to be within the valid range of days for the month
 * corresponding to the current value of the month field.
 *
 * @param   d       the day to set to
 * @return          true if the given day is valid, false otherwise
 */
bool Date::setDay(int d) {
	if (d <= numDays[month - 1]) {
		day = d;

		return true;
	}

	return false;
}

/**
 * Sets the year to the given integer.
 *
 * Validates the year to be in the range [1900,9999].
 *
 * @param   y       the year to set to
 * @return          true if the given year is valid, false otherwise
 */
bool Date::setYear(int y) {
	if (y >= 1900 && y <= 9999) {
		year = y;

		return true;
	}

	return false;
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

	for (int m = 1; m <= NUM_MONTHS; m++) {
		numDays[m - 1] = 30 + // Base. Formula below adds 1 or 0 to base.
		                 (m + (m / 8)) % 2 - // Reverses pattern at m >= 8.
		                 ((2 / m) * adj) + // Applies only to 1 <= m <= 2.
		                 ((1 / m) * adj * 2); // Applies only to m = 1.
	}
}

/******************************************************************************
 Other Member Functions
 ******************************************************************************/

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
	cout << names[month + 1] << " " << day << ", " << year << '\n';
}

/**
 * Prints to console the date in the following format: %d %B, %Y
 *
 * Example: 21 January, 2001
 */
void Date::showDate3() {
	cout << day << " " << names[month + 1] << " " << year << '\n';
}

/**
 * Determines if the given year is a leap year.
 *
 * A year is a leap year if it is exactly divisible by 4 and not exactly
 * divisible by 100 (unless it is also exactly divisible by 400).
 *
 * @param   y       the year to be checked
 * @return          true if a leap year, false otherwise
 */
bool Date::isLeapYear(int y) {
	return y % 4 == 0 && (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0));
}

/******************************************************************************
 Overloaded Operators
 ******************************************************************************/

/**
 * Prefix increment operator (++).
 *
 * Increments the day by 1.
 *
 * @return          the new date after being incremented by 1 day
 */
Date Date::operator++() {
	return Date();
}

/**
 * Postfix increment operator (++).
 *
 * Increments the day by 1.
 *
 * @return          the new date after being incremented by 1 day
 */
Date Date::operator++(int) {
	return Date();
}

/**
 * Prefix decrement operator (--).
 *
 * Decrements the day by 1.
 *
 * @return          the new date after being decremented by 1 day
 */
Date Date::operator--() {
	return Date();
}

/**
 * Prefix decrement operator (--).
 *
 * Decrements the day by 1.
 *
 * @return          the new date after being decremented by 1 day
 */
Date Date::operator--(int) {
	return Date();
}

/*
bool Date::operator>(const Date&) {
	return false;
}
*/

/**
 * Subtraction operator (-).
 *
 * Determines the number of days between two dates. Excludes the end date in
 * the calculation.
 *
 * @return          the number of days between two dates
 */
int Date::operator-(const Date& subtrahend) {
	return 0;
}

/*
bool Date::operator<(const Date&) {
	return false;
}
*/

/**
 * Stream insertion operator (<<).
 *
 *
 *
 * @return
 */
ostream& operator<<(ostream& stream, Date& date) {
	return stream;
}

/**
 * Stream extraction operator (>>).
 *
 * Prompts the user to input a date and validates it. If valid, stores the
 * date into a Date object.
 *
 * @return
 */
istream& operator>>(istream& stream, Date& date) {
	bool isValid;

	do {
		string y;
		isValid = true;

		cout << "Enter the year as an integer [1900,9999]: ";
		stream >> y;
		cout << '\n';

		if (y.empty()) {
			cout << "The input given is empty. Please try again.\n\n";

			isValid = false;
		}

		size_t length = y.length();

		for (int i = 0; isValid && i < length; i++) {
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
		cout << '\n';

		if (m.empty()) {
			cout << "The input given is empty. Please try again.\n\n";

			isValid = false;
		}

		size_t length = m.length();

		for (int i = 0; isValid && i < length; i++) {
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
		cout << '\n';

		if (d.empty()) {
			cout << "The input given is empty. Please try again.\n\n";

			isValid = false;
		}

		size_t length = d.length();

		for (int i = 0; isValid && i < length; i++) {
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