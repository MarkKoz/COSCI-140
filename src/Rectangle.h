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
	const Item& getRectangleWidth() const {
		return rectangleWidth;
	}

	/**
	 *
	 * @return
	 */
	const Item2& getRectangleLength() const {
		return rectangleLength;
	}

	/**
	 *
	 * @param width
	 */
	void setRectangleWidth(const Item& width) {
		rectangleWidth = width;
	}

	/**
	 *
	 * @param length
	 */
	void setRectangleLength(const Item2& length) {
		rectangleLength = length;
	}

	/**
	 *
	 */
	class ErrorAllocatingLengthOrWidth {
	public:
		/**
		 *
		 * @param   val
		 */
		ErrorAllocatingLengthOrWidth(const Item& val) {
			value = val;
		}

		/**
		 *
		 * @return
		 */
		const Item& getValue() const {
			return value;
		}

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
int Rectangle<Item, Item2>::rectangleCount;

#endif
