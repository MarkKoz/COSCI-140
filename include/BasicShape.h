#ifndef CH15_QUIZ_BASICSHAPE_H
#define CH15_QUIZ_BASICSHAPE_H

class BasicShape {
public:
	/**
	 * Gets the area of the shape.
	 *
	 * @return              const lvalue reference to the area field
	 */
	virtual const double& getArea() const;

	/**
	 * Assigns the passed value to the area field.
	 *
	 * @param   a           the value to assign to the area field
	 */
	void setArea(const double& a);

	/**
	 * Calculates the area of the shape.
	 */
	virtual void calcArea() = 0;

private:
	double area;
};

#endif
