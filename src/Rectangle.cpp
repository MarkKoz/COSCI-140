#include "../include/Rectangle.h"

Rectangle::Rectangle(const double& l, const double& w) {
	length = l;
	width = w;

	Rectangle::calcArea();
}

const double& Rectangle::getLength() const {
	return length;
}

const double& Rectangle::getWidth() const {
	return width;
}

void Rectangle::calcArea() {
	setArea(length * width);
}
