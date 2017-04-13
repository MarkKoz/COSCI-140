#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include "../include/Circle.h"
#include "../include/Rectangle.h"

/**
 * Determines if a given string is formatted as a real number in decimal
 * notation >= 0.
 *
 * @param   input           the string to check
 * @return                  true if format matches criteria; false otherwise
 */
bool isDecimal(const std::string& input) {
	if (input.empty()) {
		std::cout << "The input given is empty, please try again: ";

		return false;
	}

	if (input.find(" ") != std::string::npos) {
		std::cout << "Spaces are not allowed, please try again: ";

		return false;
	}

	bool hasRadix = false;

	for (char c : input) {
		if (!hasRadix && c == '.') {
			hasRadix = true;
		} else if (!std::isdigit(c)) {
			std::cout << "The value must be a positive real number in decimal "
					"form, please try again: ";

			return false;
		}
	}

	return true;
}

/**
 * Retrieves an input from the user and converts it to a double after
 * validation. Retrieves a new input if invalid.
 *
 * Invalid if call to isDecimal() returns false or if converted value = 0.
 *
 * @param   dbl             the double variable to witch the converted input
 *                          will be assigned
 */
void getInput(double& dbl) {
	std::string input;

	do {
		do {
			std::getline(std::cin, input);
		} while (!isDecimal(input));

		dbl = std::stod(input);

		if (dbl == 0) {
			std::cout << "The value must be a positive real number in decimal "
					"form, please try again: ";
		}
	} while (dbl == 0);
}

int main() {
	std::cout << std::fixed << std::showpoint << std::setprecision(2);

	double x, y, radius;

	std::cout << "Please enter the x-coordinate of the circle's centre: ";
	getInput(x);
	std::cout << "Please enter the y-coordinate of the circle's centre: ";
	getInput(y);
	std::cout << "Please enter the radius of the circle: ";
	getInput(radius);

	Circle circle = Circle(x, y, radius);
	std::cout << "The area of the circle is " << circle.getArea() << ".\n";

	double length, width;

	std::cout << "\nPlease enter the length of the rectangle: ";
	getInput(length);
	std::cout << "Please enter the width of the rectangle: ";
	getInput(width);

	Rectangle rectangle = Rectangle(length, width);
	std::cout << "The area of the " << rectangle.getLength() << " x "
	          << rectangle.getWidth() << " rectangle is "
	          << rectangle.getArea() << ".\n";

	std::cout << "\nEnter any character(s) to quit: ";
	std::cin.get();

	return 0;
}
