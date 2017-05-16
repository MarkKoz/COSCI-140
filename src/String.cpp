#include <cctype>
#include <iostream>
#include <streambuf>
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
	const int BUF_MAX = 128; // Capacity of the buffer.
	char buffer[BUF_MAX];
	int length = 0;
	char c = static_cast<char>(is.get()); // Extracts a char from the stream.

	// EOF check may be redundant since istream::get() should stop if reached.
	// TODO: Maybe check !is.eof() instead?
	while (c != EOF && !isspace(c)) {
		// Appends the contents of the buffer if it is full.
		if (length == BUF_MAX) {
			str.append(buffer, BUF_MAX);
			length = 0; // Reset so the buffer's contents can be overridden.
		}

		buffer[length++] = c; // Inserts the extracted char into the buffer.
		is.get(c); // Extracts the next char from the stream.
	}

	// Appends the contents of the buffer to this String.
	str.append(buffer, length);

	return is;
}

String& String::operator+(const String& rvalue) {
	append(rvalue.data, rvalue.length);

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
