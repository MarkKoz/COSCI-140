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

String::Result String::compare(const String& rvalue) const {
	for (int i = 0; i < (length < rvalue.length ? length : rvalue.length); ++i) {
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

	// If data array can't be reused, a new array of istream's size needs to
	// be created.
	if (size != str.length) {
		delete[] str.data;
		str.length = size;
		str.data = new char[str.length];
	}

	is >> str.data;

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
