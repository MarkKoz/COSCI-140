#ifndef CH16_QUIZ_ARRAYOFOBJECTS_H
#define CH16_QUIZ_ARRAYOFOBJECTS_H

#include "Circle.h"
#include "Rectangle.h"

/**
 * An array that can hold objects of type Item which can be indexed
 * using the [] operator.
 *
 * @tparam  Item        the type of the object to store in the array
 */
template<class Item>
class ArrayOfObjects {
public:
	/**
	 * Initialises ptrToArrayOfObjects to nullptr.
	 */
	ArrayOfObjects();

	/**
	 * Constructs an empty array ptrToArrayOfObjects of objects of type Item of
	 * size arraySize.
	 *
	 * @param   arraySize   the size with which the array should be constructed
	 * @throws  ErrorAllocatingPointerMemory  arraySize is less than zero
	 */
	ArrayOfObjects(int& arraySize);

	/**
	 * Accesses array ptrToArrayOfObjects and returns the value at index x.
	 *
	 * @param   x           the index of the array to access
	 * @return              lvalue reference to the object in the array at index
	 *                      x
	 */
	Item& operator[](const int& x) const;

	/**
	 * Used to catch potential errors caused by negative values in arraySize.
	 */
	class ErrorAllocatingPointerMemory {
	public:
		/**
		 * Constructs an object to be thrown with the the value val, which
		 * threw the exception, accessible.
		 *
		 * @param   val         the value which threw the exception
		 */
		ErrorAllocatingPointerMemory(const int& val);

		/**
		 * Gets the value of value, which threw the exception.
		 *
		 * @return              const lvalue reference to the value which threw
		 *                      the exception
		 */
		const int& getValue() const;

	private:
		int value; // The value which threw the exception.
	};

private:
	Item* ptrToArrayOfObjects;
};

#include "../src/ArrayOfObjects.cpp"

#endif
