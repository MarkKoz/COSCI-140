#ifndef CH16_QUIZ_ARRAYOFOBJECTS_H
#define CH16_QUIZ_ARRAYOFOBJECTS_H

#include "../include/Circle.h"
#include "../include/Rectangle.h"

/**
 *
 * @tparam  Item
 */
template<class Item>
class ArrayOfObjects {
public:
	/**
	 *
	 */
	ArrayOfObjects();

	/**
	 *
	 * @param   arraySize
	 */
	ArrayOfObjects(int& arraySize);

	/**
	 *
	 * @param   x
	 * @return
	 */
	Item& operator[](const int& x) const;

	/**
	 *
	 */
	class ErrorAllocatingPointerMemory {
	public:
		/**
		 *
		 * @param   val
		 */
		ErrorAllocatingPointerMemory(const int& val);

		/**
		 *
		 * @return
		 */
		const int& getValue() const;

	private:
		int value;
	};

private:
	Item* ptrToArrayOfObjects;
};

#endif
