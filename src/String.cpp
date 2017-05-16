#include <String.h>

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

void String::validateAlpha(String& str) {

}

void String::validateDigit(String& str) {

}

String& String::operator=(const String& rvalue) {
	return <#initializer#>;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
	for (int i = 0; i < length; ++i) {
		os << data[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, String& str) {
	return is;
}

String& String::operator+(const String& rvalue) {
	return <#initializer#>;
}

bool String::operator==(const String& rvalue) const {
	return false;
}

bool String::operator!=(const String& rvalue) const {
	return false;
}

bool String::operator<(const String& rvalue) const {
	return false;
}

bool String::operator>(const String& rvalue) const {
	return false;
}

bool String::operator<=(const String& rvalue) const {
	return false;
}

bool String::operator>=(const String& rvalue) const {
	return false;
}

char& String::operator[](int index) const {
	return <#initializer#>;
}
