#ifndef CH15_QUIZ_RECTANGLE_H
#define CH15_QUIZ_RECTANGLE_H

#include "BasicShape.h"

class Rectangle : protected BasicShape {
public:
	/**
	 * Constructs a Rectangle object with the given parameters and calculates
	 * its area.
	 *
	 * @param   l           the length of the rectangle
	 * @param   w           the width of the rectangle
	 */
	Rectangle(const double& l, const double& w);

	/**
	 * Gets the area of the rectangle.
	 *
	 * @return              const lvalue reference to the area field
	 */
	const double& getArea() const;

	/**
	 * Gets the length of the rectangle.
	 *
	 * @return              const lvalue reference to the length field
	 */
	const double& getLength() const;

	/**
	 * Gets the width of the rectangle.
	 *
	 * @return              const lvalue reference to the width field
	 */
	const double& getWidth() const;

	/**
	 * Calculates the area of the rectangle and sets the area field to the
	 * evaluated value.
	 */
	void calcArea() override;

private:
	double length;
	double width;
};

#endif
