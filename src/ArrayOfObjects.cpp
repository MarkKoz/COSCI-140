#include "../include/ArrayOfObjects.h"

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
ArrayOfObjects<Item>::ErrorAllocatingPointerMemory::
		ErrorAllocatingPointerMemory(const int& val) {
	value = val;
}

template<class Item>
const int& ArrayOfObjects<Item>::
		ErrorAllocatingPointerMemory::getValue() const {
	return value;
}
