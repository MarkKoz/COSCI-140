#ifndef CH16_QUIZ_RECTANGLE_H
#define CH16_QUIZ_RECTANGLE_H

/**
 * Object which represents a rectangle shape with a length and a width.
 *
 * @tparam  Item        the type of the width
 * @tparam  Item2       the type of the length
 */
template<class Item, class Item2>
class Rectangle {
public:
	/**
	 * Constructs a rectangle with a rectangleWidth and rectangleLength of 0
	 * and increments rectangleCount by one.
	 */
	Rectangle();

	/**
	 * Constructs a rectangle with a rectangleWidth of width and
	 * rectangleLength of length and increments rectangleCount by one.
	 *
	 * @param   width       the width of the rectangle
	 * @param   length      the length of the rectangle
	 * @throws  ErrorAllocatingLengthOrWidth  width or length is less than zero
	 */
	Rectangle(const Item& width, const Item2& length);

	/**
	 * Gets the total number of rectangle objects that have been constructed.
	 *
	 * @return              const lvalue reference to rectangleCount
	 */
	const int& getRectangleCount() const;

	/**
	 * Gets the width rectangleWidth of the rectangle.
	 *
	 * @return              const lvalue reference to rectangleWidth
	 */
	const Item& getRectangleWidth() const;

	/**
	 * Gets the length rectangleLength of the rectangle.
	 *
	 * @return              const lvalue reference to rectangleLength
	 */
	const Item2& getRectangleLength() const;

	/**
	 * Assigns the value of width to the rectangle's width rectangleWidth.
	 *
	 * @param   width       the width to which to set the rectangle
	 */
	void setRectangleWidth(const Item& width);

	/**
	 * Assigns the value of length to the rectangle's length rectangleLength.
	 *
	 * @param   length      the length to which to set the rectangle
	 */
	void setRectangleLength(const Item2& length);

	/**
	 * Used to catch potential errors caused by negative values for the width or
	 * length of the rectangle.
	 */
	class ErrorAllocatingLengthOrWidth {
	public:
		/**
		 * Constructs an object to be thrown with the the value val, which
		 * threw the exception, accessible.
		 *
		 * @param   val         the value which threw the exception
		 */
		ErrorAllocatingLengthOrWidth(const Item& val);

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
	static int rectangleCount; // The total amount of Rectangles constructed.
	Item rectangleWidth;
	Item2 rectangleLength;
};

#include "../src/Rectangle.cpp"

#endif
