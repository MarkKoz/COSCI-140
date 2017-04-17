#ifndef CH16_QUIZ_CIRCLE_H
#define CH16_QUIZ_CIRCLE_H

/**
 * Object which represents a circle shape with a radius.
 *
 * @tparam  Item        the type of the radius
 */
template<class Item>
class Circle {
public:
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
	Circle(const Item& radius);

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
	const Item& getCircleRadius() const;

	/**
	 * Assigns the value of radius to the circle's radius circleRadius.
	 *
	 * @param   radius      the radius to which to set the circle
	 */
	void setCircleRadius(const Item& radius);

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
		ErrorAllocatingMemory(const Item& val);

		/**
		 * Gets the value of value, which threw the exception.
		 *
		 * @return              const lvalue reference to the value which threw
		 *                      the exception
		 */
		const Item& getValue() const;

	private:
		Item value; // The value which threw the exception.
	};

private:
	static int circleCount; // The total amount of Circles constructed.
	Item circleRadius;
};

#include "../src/Circle.cpp"

#endif
