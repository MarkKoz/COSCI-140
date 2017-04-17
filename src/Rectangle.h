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
	const int& getRectangleCount() const;

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
	class ErrorAllocatingLengthOrWidth {
	public:
		/**
		 *
		 * @param   val
		 */
		ErrorAllocatingLengthOrWidth(const Item& val);

		/**
		 *
		 * @return
		 */
		const Item& getValue() const;

	private:
		Item value;
	};

private:
	static int rectangleCount;
	Item rectangleWidth;
	Item2 rectangleLength;
};

template<class Item, class Item2>
Rectangle<Item, Item2>::Rectangle() {
	++rectangleCount;
	rectangleWidth, rectangleLength = 0;

}

template<class Item, class Item2>
Rectangle<Item, Item2>::Rectangle(const Item& width, const Item2& length) {
	if (width < 0) {
		throw ErrorAllocatingLengthOrWidth(width);
	}

	if (length < 0) {
		throw ErrorAllocatingLengthOrWidth(length);
	}

	++rectangleCount;
	rectangleWidth = width;
	rectangleLength = length;
}

template<class Item, class Item2>
const int& Rectangle<Item, Item2>::getRectangleCount() const {
	return rectangleCount;
}

template<class Item, class Item2>
const Item& Rectangle<Item, Item2>::getRectangleWidth() const {
	return rectangleWidth;
}

template<class Item, class Item2>
const Item2& Rectangle<Item, Item2>::getRectangleLength() const {
	return rectangleLength;
}

template<class Item, class Item2>
void Rectangle<Item, Item2>::setRectangleWidth(const Item& width) {
	rectangleWidth = width;
}

template<class Item, class Item2>
void Rectangle<Item, Item2>::setRectangleLength(const Item2& length) {
	rectangleLength = length;
}

template<class Item, class Item2>
Rectangle<Item, Item2>::ErrorAllocatingLengthOrWidth::ErrorAllocatingLengthOrWidth(const Item& val) {
	value = val;
}

template<class Item, class Item2>
const Item& Rectangle<Item, Item2>::ErrorAllocatingLengthOrWidth::getValue() const {
	return value;
}

#endif
