#include <String.h>

String::String() {

}

String::String(const char* cstr) {

}

String::~String() {

}

int String::getLength() const {
	return 0;
}

void String::validateAlpha(String& str) {

}

void String::validateDigit(String& str) {

}


String& String::operator=(const String& rvalue) {
	return <#initializer#>;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
	return <#initializer#>;
}

std::istream& operator>>(std::istream& is, String& str) {
	return <#initializer#>;
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
