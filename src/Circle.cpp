#include "Circle.h"

Circle::Circle() {
	nextNodeLink = nullptr;
	++circleCount;
	circleRadius = 0;
};

Circle::Circle(const Circle& circle) {
	nextNodeLink = nullptr;
	++circleCount;
	circleRadius = circle.getCircleRadius();
}

Circle::Circle(const int &radius) {
	if (radius < 0) {
		throw ErrorAllocatingMemory(radius);
	}

	nextNodeLink = nullptr;
	++circleCount;
	circleRadius = radius;
};

Circle::~Circle() {
	--circleCount;
}

const int& Circle::getCircleCount() const {
	return circleCount;
}

const int& Circle::getCircleRadius() const {
	return circleRadius;
}

Circle::ErrorAllocatingMemory::ErrorAllocatingMemory(const int& val) {
	value = val;
}

const int& Circle::ErrorAllocatingMemory::getValue() const {
	return value;
}

int Circle::circleCount = 0;
