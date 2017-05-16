#include <iostream>
#include "String.h"

String::String() {
	data == nullptr;
	length = 0;
}

String::String(const char* cstr) {
	length = 0;

	while (cstr[length] != '\0') { // Determines the length of cstr.
		++length;
	}

	data = new char[length]; // Creates a char array of the appropriate length.

	for (int i = 0; i < length; ++i) { // Populates the array.
		data[i] = cstr[i];
	}
}

String::~String() {
	if (data != nullptr) {
		delete[] data;
	}
}

int String::getLength() const {
	return length;
}

void String::append(const char* str, int size) {
	// TODO: Pass a c string instead so the overloaded constructor can be used.
	if (data == nullptr || length == 0) { // If this String is empty.
		data = new char[size];
		length = size;

		for (int i = 0; i < size; ++i) { // Copies the String to be appended.
			data[i] = str[i];
		}
	} else {
		char buffer[length];
		int bufLen = length;

		// Copies this String into the buffer.
		for (int i = 0; i < length; ++i) {
			buffer[i] = data[i];
		}

		// Deletes data and creates a new array with enough space for both
		// Strings.
		delete[] data;
		length += size;
		data = new char[length];

		// Copies the String in the buffer.
		for (int i = 0; i < bufLen; ++i) {
			data[i] = buffer[i];
		}

		// Copies the String to be appended.
		for (int i = bufLen; i < length; ++i) {
			data[i] = str[i - bufLen];
		}
	}
}

String::Result String::compare(const String& rvalue) const {
	if (length != rvalue.length) { // Returns based on string length
		return length < rvalue.length ? Result::lesser : Result::greater;
	}

	// Otherwise performs lexicographical comparison.
	for (int i = 0; i < length; ++i) {
		if (data[i] != rvalue.data[i]) { // First unequal values reached.
			return data[i] < rvalue.data[i] ? Result::lesser : Result::greater;
		}
	}

	return Result::equal; // Everything is equal.
}

void String::validateAlpha(String& str) {

}

void String::validateDigit(String& str) {

}

String& String::operator=(const String& rvalue) {
	int rLength = rvalue.getLength();

	if (this != &rvalue) { // Checks for self-assignment.
		// If data array can't be reused, a new array of rvalue's size needs to
		// be created.
		if (rLength != length) {
			delete[] data;
			length = rLength;
			data = new char[length];
		}

		for (int i = 0; i < length; ++i) { // Populates the array.
			data[i] = rvalue.data[i];
		}
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
	for (int i = 0; i < str.length; ++i) {
		os << str.data[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, String& str) {
	const int size = static_cast<int>(is.width()); // Size of the stream.
	int extracted = 0;
	char buffer[128];
	int length = 0;
	char c = static_cast<char>(is.rdbuf()->sgetc());

	while (extracted < size) {
		if (length == sizeof(buffer) / sizeof(char)) {
			str.append(buffer, sizeof(buffer) / sizeof(char));
			length = 0;
		}

//		buffer[length++] = static_cast<char>(is.get());
		buffer[length++] = c;
		++extracted;
		c = static_cast<char>(is.rdbuf()->snextc());
	}

	str.append(buffer, length);
	is.width(0);

	return is;
}

String& String::operator+(const String& rvalue) {
	char* buffer = data; // Stores data in a buffer before deleting it.
	int bufLen = length;

	// Deletes data and creates a new array with enough space for both Strings.
	delete[] data;
	length += rvalue.getLength();
	data = new char[length];

	for (int i = 0; i < bufLen; ++i) { // Copies the left String.
		data[i] = buffer[i];
	}

	for (int i = bufLen; i < length; ++i) { // Copies the right String.
		data[i] = rvalue[i - bufLen];
	}

	return *this;
}

bool String::operator==(const String& rvalue) const {
	return compare(rvalue) == Result::equal;
}

bool String::operator!=(const String& rvalue) const {
	return compare(rvalue) != Result::equal;
}

bool String::operator<(const String& rvalue) const {
	return compare(rvalue) == Result::lesser;
}

bool String::operator>(const String& rvalue) const {
	return compare(rvalue) == Result::greater;
}

bool String::operator<=(const String& rvalue) const {
	return compare(rvalue) == Result::lesser || Result::equal;
}

bool String::operator>=(const String& rvalue) const {
	return compare(rvalue) == Result::greater || Result::equal;
}

char& String::operator[](int index) const {
	return data[index];
}
