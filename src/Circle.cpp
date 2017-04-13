#include "../include/BasicShape.h"
#include "../include/Circle.h"

Circle::Circle(const double& x, const double& y, const double& r) {
	centerX = x;
	centerY = y;
	radius = r;

	Circle::calcArea();
}

const double& Circle::getArea() const {
	return BasicShape::getArea();
}

const double& Circle::getCenterX() const {
	return centerX;
}

const double& Circle::getCenterY() const {
	return centerY;
}

void Circle::calcArea() {
	setArea(3.14159 * radius * radius);
}
