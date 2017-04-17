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
	ArrayOfObjects() {
		ptrToArrayOfObjects = nullptr;
	}

	/**
	 *
	 * @param   arraySize
	 */
	ArrayOfObjects(int& arraySize) {
		if (arraySize < 0){
			throw ErrorAllocatingPointerMemory(arraySize);
		}

		ptrToArrayOfObjects = new Item[arraySize];
	}

	/**
	 *
	 * @param   x
	 * @return
	 */
	Item& operator[](const int& x) const {
		return ptrToArrayOfObjects[x];
	}

	/**
	 *
	 */
	class ErrorAllocatingPointerMemory {
	public:
		/**
		 *
		 * @param   val
		 */
		ErrorAllocatingPointerMemory(const int& val) {
			value = val;
		}

		/**
		 *
		 * @return
		 */
		const int& getValue() const {
			return value;
		}

	private:
		int value;
	};

private:
	Item* ptrToArrayOfObjects;
};

#endif
