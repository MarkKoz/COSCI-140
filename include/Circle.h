#ifndef CH17_QUIZ_CIRCLE_H
#define CH17_QUIZ_CIRCLE_H

class Circle {
public:
	Circle *nextNodeLink;

	/**
	 * Constructs a circle with a circleRadius of 0 and increments circleCount
	 * by one.
	 */
	Circle();

	/**
	 * Constructs a circle with a circleRadius of radius and increments
	 * circleCount by one.
	 *
	 * @param   radius      the radius of the circle
	 * @throws  ErrorAllocatingMemory   radius is less than zero
	 */
	Circle(const int &radius);

	/**
	 * Decrements circleCount when the object is destroyed.
	 */
	~Circle();

	/**
	 * Gets the total number of circle objects that have been constructed.
	 *
	 * @return              const lvalue reference to circleCount
	 */
	const int& getCircleCount() const;

	/**
	 * Gets the radius circleRadius of the circle.
	 *
	 * @return              const lvalue reference to circleRadius
	 */
	const int& getCircleRadius() const;

	/**
	 * Used to catch potential errors caused by negative values for the radius
	 * of the circle.
	 */
	class ErrorAllocatingMemory {
	public:
		/**
		 * Constructs an object to be thrown with the the value val, which
		 * threw the exception, accessible.
		 *
		 * @param   val         the value which threw the exception
		 */
		ErrorAllocatingMemory(const int& val);

		/**
		 * Gets the value of value, which threw the exception.
		 *
		 * @return              const lvalue reference to the value which threw
		 *                      the exception
		 */
		const int& getValue() const;

	private:
		int value; // The value which threw the exception.
	};

private:
	static int circleCount; // The total amount of current Circle objects.
	int circleRadius;
};

#endif
