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
}

/**
 * Overloaded constructor.
 *
 * @param   m       the month
 * @param   d       the day
 * @param   y       the year
 */
Date::Date(int m, int d, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
	setNames();
}

/******************************************************************************
 Mutators
 ******************************************************************************/

/**
 * Sets the month to the given integer.
 *
 * Validates the month to be in the range [1, 12].
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
 * @param   d       the day to set to
 * @return          true if the given day is valid, false otherwise
 */
bool Date::setDay(int d) {
	return false;
}

/**
 * Sets the year to the given integer.
 *
 * Validates the year to be in the range [1900, 9999].
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

}

/**
 * Populates the numDays array with the number of days for each month.
 */
void Date::setDays() {

}

/******************************************************************************
 Other Functions
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
int Date::operator-(const Date&) {
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
ostream& operator<<(ostream&, Date&) {
	return <#initializer#>;
}

/**
 * Stream extraction operator (>>).
 *
 *
 *
 * @return
 */
istream& operator>>(istream&, Date&) {
	return <#initializer#>;
}
