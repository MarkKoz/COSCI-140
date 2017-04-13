#ifndef CH15_QUIZ_CIRCLE_H
#define CH15_QUIZ_CIRCLE_H

#include "BasicShape.h"

class Circle : protected BasicShape {
public:
	/**
	 * Constructs a Circle object with the given parameters and calculates
	 * its area.
	 *
	 * @param   x           the x-coordinate of the circle's centre
	 * @param   y           the y-coordinate of the circle's centre
	 * @param   r           the circle's radius
	 */
	Circle(const double& x, const double& y, const double& r);

	/**
	 * Gets the area of the circle.
	 *
	 * @return              const lvalue reference to the area field
	 */
	const double& getArea() const;

	/**
	 * Gets the x-coordinate of the centre of the circle.
	 *
	 * @return              const lvalue reference to the getCenterX field
	 */
	const double& getCenterX() const;

	/**
	 * Gets the y-coordinate of the centre of the circle.
	 *
	 * @return              const lvalue reference to the getCenterY field
	 */
	const double& getCenterY() const;

	/**
	 * Calculates the area of the circle using 3.14159 for pi and sets the
	 * area field to the evaluated value.
	 */
	void calcArea() override;

private:
	double centerX; // x-coordinate of centre.
	double centerY; // y-coordinate of centre.
	double radius;
};

#endif
