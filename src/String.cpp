#include <cstring>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include "../include/String.h"

String::String() {
	// Creates an empty char array with null terminator.
	data = new char[1] {'\0'};
	length = 0;
}

String::String(const String& str) {
	data = new char[str.length + 1];
	length = str.length;
	strcpy(data, str.data);
}

String::String(const char* cstr) {
	length = 0;

	while (cstr[length] != '\0') { // Determines the length of cstr.
		++length;
	}

	// Creates a char array of the appropriate length. + 1 for null terminator.
	data = new char[length + 1];
	strcpy(data, cstr);
}

String::~String() {
	delete[] data;
}

int String::getLength() const {
	return length;
}

void String::append(const char* str, int size) {
	length += size; // Length of both strings

	char buffer[length + 1]; // Buffer to hold both strings. +1 for null.
	buffer[0] = '\0'; // strcat needs a null terminator in the dest string.
	std::strcat(buffer, data); // Appends this String to the buffer.
	std::strcat(buffer, str); // Appends the passed c string to the buffer.

	// Resizes this String to be able to hold both strings.
	delete[] data;
	data = new char[length + 1];
	std::strcpy(data, buffer); // Copies the buffer into this String.
}

String::Result String::compare(const String& rvalue) const {
	if (length != rvalue.length) { // Returns based on string length.
		return length < rvalue.length ? Result::lesser : Result::greater;
	}

	// Otherwise performs lexicographical comparison.
	for (int i = 0; i < length; ++i) {
		if (data[i] != rvalue[i]) { // First unequal values reached.
			return data[i] < rvalue[i] ? Result::lesser : Result::greater;
		}
	}

	return Result::equal; // Everything is equal.
}

void String::validateAlpha(String& str) {
	bool isInvalid;

	do {
		isInvalid = false; // Resets boolean at the start of every iteration.

		for (int i = 0; i < str.length && !isInvalid; ++i) {
			if (!isalpha(str[i])) {
				isInvalid = true;
			}
		}

		if (isInvalid) { // Prompts for a new input.
			std::cout << "The input entered does not consist solely of "
					"alphabetical characters. Please try again:\n";
			std::cin >> str;
		}
	} while (isInvalid);
}

void String::validateDigit(String& str) {
	bool isInvalid;

	do {
		isInvalid = false; // Resets boolean at the start of every iteration.

		for (int i = 0; i < str.length && !isInvalid; ++i) {
			if (!isdigit(str[i])) {
				isInvalid = true;
			}
		}

		if (isInvalid) { // Prompts for a new input.
			std::cout << "The input entered does not consist solely of decimal "
					"digits. Please try again:\n";
			std::cin >> str;
		}
	} while (isInvalid);
}

String& String::operator=(const String& rvalue) {
	if (this != &rvalue) { // Checks for self-assignment.
		// If data array can't be reused, a new array of rvalue's size needs to
		// be created.
		if (rvalue.length != length) {
			delete[] data;
			length = rvalue.length;
			data = new char[length + 1]; // + 1 for null terminator.
		}

		strcpy(data, rvalue.data);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
	for (int i = 0; i < str.length; ++i) {
		os << str[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, String& str) {
	// Replaces the passed String with an empty String.
	delete[] str.data;
	str.length = 0;
	str.data = new char[1] {'\0'};

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
	if (index > length || index < 0) {
		throw std::out_of_range("String::operator[](): index is out of range.");
	}

	return data[index];
}
