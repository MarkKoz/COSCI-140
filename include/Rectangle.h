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
	Rectangle(const Item& width, const Item2& length);

	/**
	 *
	 * @return
	 */
	int getRectangleCount() const;

	/**
	 *
	 * @return
	 */
	const Item& getRectangleWidth() const;

	/**
	 *
	 * @return
	 */
	const Item2& getRectangleLength() const;

	/**
	 *
	 * @param width
	 */
	void setRectangleWidth(const Item& width);

	/**
	 *
	 * @param length
	 */
	void setRectangleLength(const Item2& length);

	/**
	 *
	 */
	template<class T>
	class ErrorAllocatingLengthOrWidth {
	public:
		/**
		 *
		 * @param   val
		 */
		ErrorAllocatingLengthOrWidth(const T& val);

		/**
		 *
		 * @return
		 */
		const T& getValue() const;

	private:
		T value;
	};

private:
	static int rectangleCount;
	Item rectangleWidth;
	Item2 rectangleLength;
};

#endif
