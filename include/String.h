#ifndef FINAL_STRING_H
#define FINAL_STRING_H

#include <iostream>

class String {
	/**
	 * Stream insertion operator overload.
	 *
	 * Inserts the characters of the passed String into the passed ostream.
	 *
	 * @param   os          the ostream object
	 * @param   str         the String to be inserted into the stream
	 * @return              the ostream object
	 */
	friend std::ostream& operator<<(std::ostream& os, const String& str);

	/**
	 * Stream extraction operator overload.
	 *
	 * Extracts characters from the passed istream and assigns them to the
	 * passed String. Stops extracting characters from the stream if EOF is
	 * reached or if a whitespace character is reached as defined by
	 * std::locale::classic.
	 *
	 * @param   is          the istream object
	 * @param   str         the String to which the extracted characters will be
	 *                      assigned
	 * @return              the istream object
	 */
	friend std::istream& operator>>(std::istream& is, String& str);

public:
	/**
	 * Enumeration of possible results of a comparison.
	 */
	enum Result {
		lesser = -1,
		equal = 0,
		greater = 1
	};

	/**
	 * Constructs an empty String.
	 */
	String();

	/**
	 * Constructs a String which is a copy of the passed String.
	 *
	 * @param str
	 */
	String(const String& str);

	/**
	 * Constructs a String with the value of the passed C String.
	 *
	 * @param   cstr        the C string the value of which will be given to
	 *                      the constructed String
	 */
	String(const char* cstr);

	/**
	 * Deletes the internal C string which holds this String's character data.
	 */
	~String();

	/**
	 * Gets the length of this String.
	 *
	 * @return              the length of this String
	 */
	int getLength() const;

	/**
	 * Appends the passed amount of characters from the passed C string to
	 * this String.
	 *
	 * @param   str         the C string to append
	 * @param   size        the amount of characters to append
	 */
	void append(const char* str, int size);

	/**
	 * Performs a lexicographical comparison on this String and the passed
	 * String. If the comparison finds the Strings to be equal, the return
	 * value will be based on the Strings' lengths.
	 *
	 * @param   str         the other String to compare
	 * @return              Result::Lesser if this String is less than the
	 *                      passed String; Result::Greater if this String is
	 *                      greater than the passed String; Result::Equal
	 *                      otherwise
	 */
	Result compare(const String& str) const;

	/**
	 * Validates the passed String consists only of alphabetical letters. If
	 * invalid, prompts for a new input until a valid input is entered.
	 *
	 * Alphabetical letters are any of:
	 * a b c d e f g h i j k l m n o p q r s t u v w x y z
	 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	 *
	 * @param   str         the String to validate
	 */
	static void validateAlpha(String& str);

	/**
	 * Validates the passed String consists only of decimal digit characters.
	 * If invalid, prompts for a new input until a valid input is entered.
	 *
	 * Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9
	 *
	 * @param   str         the String to validate
	 */
	static void validateDigit(String& str);

	/**
	 * Binary infix assignment operator overload.
	 *
	 * Performs non copy-and-swap copy assignment i.e. assigns the value of the
	 * passed String to this String by copy.
	 *
	 * @param   rvalue      the String on the right side of the expression
	 * @return              this String
	 */
	String& operator=(const String& rvalue);

	/**
	 * Binary infix addition operator overload.
	 *
	 * Concatenates two Strings. Uses String::append to perform the
	 * concatenation.
	 *
	 * @param   rvalue      the String on the right side of the expression
	 * @return              this String
	 */
	String& operator+(const String& rvalue);

	/**
	 * Binary infix equal to operator overload.
	 *
	 * Determines if two Strings equal each other by calling String::compare
	 * to perform a lexicographical comparison.
	 *
	 * @param   rvalue      the String on the right side of the expression
	 * @return              true if the Strings are equal; false otherwise
	 */
	bool operator==(const String& rvalue) const;

	/**
	 * Binary infix not equal to operator overload.
	 *
	 * Determines if two Strings do not equal each other by calling
	 * String::compare to perform a lexicographical comparison.
	 *
	 * @param   rvalue      the String on the right side of the expression
	 * @return              true if the Strings are not equal; false otherwise
	 */
	bool operator!=(const String& rvalue) const;

	/**
	 * Binary infix less than operator overload.
	 *
	 * Determines if this String is less than the passed String by calling
	 * String::compare to perform a lexicographical comparison.
	 *
	 * @param   rvalue      the String on the right side of the expression
	 * @return              true if the left String is less than the right
	 *                      String; false otherwise
	 */
	bool operator<(const String& rvalue) const;

	/**
	 * Binary infix greater than operator overload.
	 *
	 * Determines if this String is greater than the passed String by calling
	 * String::compare to perform a lexicographical comparison.
	 *
	 * @param   rvalue      the String on the right side of the expression
	 * @return              true if the left String is greater than the right
	 *                      String; false otherwise
	 */
	bool operator>(const String& rvalue) const;

	/**
	 * Binary infix less than or equal to operator overload.
	 *
	 * Determines if this String is less than or equal to the passed String
	 * by calling String::compare to perform a lexicographical comparison.
	 *
	 * String::compare is called to perform a lexicographical comparison on
	 * the two Strings.
	 *
	 * @param   rvalue      the String on the right side of the expression
	 * @return              true if the left String is less than or equal to the
	 *                      right String; false otherwise
	 */
	bool operator<=(const String& rvalue) const;

	/**
	 * Binary infix greater than or equal to operator overload.
	 *
	 * Determines if this String is greater than or equal to the passed String
	 * by calling String::compare to perform a lexicographical comparison.
	 *
	 * @param   rvalue      the String on the right side of the expression
	 * @return              true if the left String is greater than or equal
	 *                      to the right String; false otherwise
	 */
	bool operator>=(const String& rvalue) const;

	/**
	 * Unary postfix subscript operator overload.
	 *
	 * Accesses this String like an array and retrieves the character at the
	 * passed index.
	 *
	 * @param   index       the index at which to access this String
	 * @return              the char at the passed index
	 */
	char& operator[](int index) const;

private:
	char* data; // C string which represents the value of this String.
	int length; // Number of characters excluding the null terminator.
};

#endif
