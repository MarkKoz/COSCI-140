#ifndef CH16_QUIZ_ARRAYOFOBJECTS_H
#define CH16_QUIZ_ARRAYOFOBJECTS_H

#include "Circle.h"
#include "Rectangle.h"

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

template<class Item>
ArrayOfObjects<Item>::ArrayOfObjects() {
	ptrToArrayOfObjects = nullptr;
}

template<class Item>
ArrayOfObjects<Item>::ArrayOfObjects(int& arraySize) {
	if (arraySize < 0){
		throw ErrorAllocatingPointerMemory(arraySize);
	}

	ptrToArrayOfObjects = new Item[arraySize];
}

template<class Item>
Item& ArrayOfObjects<Item>::operator[](const int& x) const {
	return ptrToArrayOfObjects[x];
}

template<class Item>
ArrayOfObjects<Item>::ErrorAllocatingPointerMemory::ErrorAllocatingPointerMemory(const int& val) {
	value = val;
}

template<class Item>
const int& ArrayOfObjects<Item>::ErrorAllocatingPointerMemory::getValue() const {
	return value;
}

#endif
