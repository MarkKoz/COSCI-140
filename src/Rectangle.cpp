#include "../include/Rectangle.h"

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
int Rectangle<Item, Item2>::getRectangleCount() const {
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
