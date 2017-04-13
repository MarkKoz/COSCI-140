#include <iomanip>
#include <iostream>
#include <string>
#include "../include/Circle.h"
#include "../include/Rectangle.h"

bool validate(const std::string& input) {
	return false;
}

int main() {
	std::cout << std::fixed << std::showpoint << std::setprecision(2);

	std::string x;
	std::string y;
	std::string radius;

	std::cout << "Please enter the x-coordinate of the circle's centre: ";
	std::getline(std::cin, x);
	std::cout << "Please enter the y-coordinate of the circle's centre: ";
	std::getline(std::cin, y);
	std::cout << "Please enter the radius of the circle: ";
	std::getline(std::cin, radius);

	Circle circle = Circle(std::stod(x), std::stod(y), std::stod(radius));
	std::cout << "The area of the circle is " << circle.getArea() << ".\n";

	std::string length;
	std::string width;

	std::cout << "\nPlease enter the length of the rectangle: ";
	std::getline(std::cin, length);
	std::cout << "Please enter the width of the rectangle: ";
	std::getline(std::cin, width);

	Rectangle rectangle = Rectangle(std::stod(length), std::stod(width));
	std::cout << "The area of the " << rectangle.getLength() << " x "
	          << rectangle.getWidth() << " rectangle is "
	          << rectangle.getArea() << ".\n";

	return 0;
}
