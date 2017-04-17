#ifndef CH16_QUIZ_CIRCLE_H
#define CH16_QUIZ_CIRCLE_H

/**
 *
 * @tparam  Item
 */
template<class Item>
class Circle {
public:
	/**
	 *
	 */
	Circle();

	/**
	 *
	 * @param   radius
	 */
	Circle(const Item& radius);

	/**
	 *
	 * @return
	 */
	const int& getCircleCount() const;

	/**
	 *
	 * @return
	 */
	const Item& getCircleRadius() const;

	/**
	 *
	 * @param   radius
	 */
	void setCircleRadius(const Item& radius);

	/**
	 *
	 */
	class ErrorAllocatingMemory {
	public:
		/**
		 *
		 * @param   val
		 */
		ErrorAllocatingMemory(const Item& val);

		/**
		 *
		 * @return
		 */
		const Item& getValue() const;

	private:
		Item value;
	};

private:
	static int circleCount;
	Item circleRadius;
};

template<class Item>
Circle<Item>::Circle() {
	++circleCount;
	circleRadius = 0;
};

template<class Item>
Circle<Item>::Circle(const Item &radius) {
	if (radius < 0) {
		throw ErrorAllocatingMemory(radius);
	}

	++circleCount;
	circleRadius = radius;
};

template<class Item>
const int& Circle<Item>::getCircleCount() const {
	return circleCount;
}

template<class Item>
const Item& Circle<Item>::getCircleRadius() const {
	return circleRadius;
}

template<class Item>
void Circle<Item>::setCircleRadius(const Item& radius) {
	circleRadius = radius;
}

template<class Item>
Circle<Item>::ErrorAllocatingMemory::ErrorAllocatingMemory(const Item& val) {
	value = val;
}

template<class Item>
const Item& Circle<Item>::ErrorAllocatingMemory::getValue() const {
	return value;
}

template<class Item>
int Circle<Item>::circleCount;

#endif
