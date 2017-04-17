#ifndef CH16_QUIZ_RECTANGLE_H
#define CH16_QUIZ_RECTANGLE_H

/**
 *
 * @tparam  Item
 * @tparam  Item2
 */
template<class Item, class Item2>
class Rectangle {
public:
	/**
	 *
	 */
	Rectangle();

	/**
	 *
	 * @param width
	 * @param length
	 */
	Rectangle(Item width, Item2 length);

	/**
	 *
	 * @return
	 */
	int getRectangleCount() const;

	/**
	 *
	 * @return
	 */
	Item getRectangleWidth() const;

	/**
	 *
	 * @return
	 */
	Item2 getRectangleLength() const;

	/**
	 *
	 * @param width
	 */
	void setRectangleWidth(Item width);

	/**
	 *
	 * @param length
	 */
	void setRectangleLength(Item2 length);

	/**
	 *
	 */
	class ErrorAllocatingLengthOrWidth {
	public:
		/**
		 *
		 * @param   val
		 */
		ErrorAllocatingLengthOrWidth(Item val);

		/**
		 *
		 * @param   val
		 */
		ErrorAllocatingLengthOrWidth(Item2 val);

		/**
		 *
		 * @return
		 */
		Item getValue() const;

		/**
		 *
		 * @return
		 */
		Item2 getValue() const;

	private:
		Item value;
		Item2 value2;
	};

private:
	static int rectangleCount;
	Item rectangleWidth;
	Item2 rectangleLength;
};

#endif
