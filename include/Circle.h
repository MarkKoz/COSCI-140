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

#endif
