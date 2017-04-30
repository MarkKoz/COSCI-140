#include "../include/Circle.h"

Circle::Circle() {
	++circleCount;
	circleRadius = 0;
};

Circle::Circle(const int &radius) {
	if (radius < 0) {
		throw ErrorAllocatingMemory(radius);
	}

	++circleCount;
	circleRadius = radius;
};

const int& Circle::getCircleCount() const {
	return circleCount;
}

const int& Circle::getCircleRadius() const {
	return circleRadius;
}

void Circle::setCircleRadius(const int& radius) {
	circleRadius = radius;
}

Circle::ErrorAllocatingMemory::ErrorAllocatingMemory(const int& val) {
	value = val;
}

const int& Circle::ErrorAllocatingMemory::getValue() const {
	return value;
}

int Circle::circleCount = 0;
