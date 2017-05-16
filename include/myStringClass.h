#ifndef FINAL_STRING_H
#define FINAL_STRING_H

#include <iostream>

class myStringClass {
	/**
	 * Stream insertion operator overload.
	 *
	 * Inserts the value of the passed String object into the passed ostream.
	 *
	 * @param   os          lvalue reference to the ostream object
	 * @param   str         const lvalue reference to the String object to be
	 *                      inserted into the stream
	 * @return              lvalue reference to the passed ostream object
	 */
	friend std::ostream& operator<<(std::ostream& os, const myStringClass& str);

	/**
	 * Stream extraction operator overload.
	 *
	 * Extracts the value from the passed istream and assigns it to the passed
	 * String object.
	 *
	 * @param   is          lvalue reference to the istream object
	 * @param   str         lvalue reference to the String object to which
	 *                      the value read will be assigned
	 * @return              lvalue reference to the passed istream object
	 */
	friend std::istream& operator>>(std::istream& is, myStringClass& str);

public:
	/**
	 * Constructs an empty String object.
	 */
	myStringClass();

	// TODO: Add a better description.
	/**
	 * Overloaded constructor.
	 *
	 * @param   str         pointer to the const C string to be set as the
	 *                      value of the constructed String object.
	 */
	myStringClass(const char* str);

	// TODO: Add a better description.
	/**
	 * Destructor.
	 */
	~myStringClass();

	// TODO: Add a better description and return value.
	/**
	 * Gets the length of the value of this String object.
	 *
	 * @return              the length of the value of this String object
	 */
	int stringLength() const;

	// TODO: Add a better description.
	/**
	 * Binary infix assignment operator overload.
	 *
	 * @param   rvalue      const lvalue reference to the String object on
	 *                      the right side of the expression
	 * @return              lvalue reference to String object on the left
	 *                      side of the expression
	 */
	myStringClass& operator=(const myStringClass& rvalue);

	/**
	 * Unary postfix subscript operator overload.
	 *
	 * Accesses the value of this String and retrieves the character at the
	 * passed index.
	 *
	 * @param   index       the index at which to access this String.
	 * @return              const lvalue reference to the char at the passed
	 *                      index
	 */
	char& operator[](int index) const;

	/**
	 * Binary infix addition operator overload.
	 *
	 * Concatenates the String objects on both sides of the expression.
	 *
	 * @param   rvalue      const lvalue reference to the String object on
	 *                      the right side of the expression
	 * @return              lvalue reference to String object on the left
	 *                      side of the expression
	 */
	myStringClass& operator+(const myStringClass& rvalue);

	/**
	 * Binary infix equal to operator overload.
	 *
	 * Determines if the values of the String objects on both sides of the
	 * expression equal each other.
	 *
	 * @param   rvalue      const lvalue reference to the String object on
	 *                      the right side of the expression
	 * @return              true if the values are equal; false otherwise
	 */
	bool operator==(const myStringClass& rvalue) const;

	/**
	 * Binary infix not equal to operator overload.
	 *
	 * Determines if the values of the String objects on both sides of the
	 * expression do not equal each other.
	 *
	 * @param   rvalue      const lvalue reference to the String object on
	 *                      the right side of the expression
	 * @return              true if the values are not equal; false otherwise
	 */
	bool operator!=(const myStringClass& rvalue) const;

	/**
	 * Binary infix less than operator overload.
	 *
	 * Determines if the value of the String object on the left side of the
	 * expression is less than the value of the String object on the right
	 * side of the expression.
	 *
	 * @param   rvalue      const lvalue reference to the String object on
	 *                      the right side of the expression
	 * @return              true if the left value is less than the right value;
	 *                      false otherwise
	 */
	bool operator<(const myStringClass& rvalue) const;

	/**
	 * Binary infix greater than operator overload.
	 *
	 * Determines if the value of the String object on the left side of the
	 * expression is greater than the value of the String object on the right
	 * side of the expression.
	 *
	 * @param   rvalue      const lvalue reference to the String object on
	 *                      the right side of the expression
	 * @return              true if the left value is greater than the right
	 *                      value; false otherwise
	 */
	bool operator>(const myStringClass& rvalue) const;

	/**
	 * Binary infix less than or equal to operator overload.
	 *
	 * Determines if the value of the String object on the left side of the
	 * expression is less than or equal to the value of the String object on
	 * the right side of the expression.
	 *
	 * @param   rvalue      const lvalue reference to the String object on
	 *                      the right side of the expression
	 * @return              true if the left value is less than or equal to the
	 *                      right value; false otherwise
	 */
	bool operator<=(const myStringClass& rvalue) const;

	/**
	 * Binary infix greater than or equal to operator overload.
	 *
	 * Determines if the value of the String object on the left side of the
	 * expression is greater than or equal to the value of the String object on
	 * the right side of the expression.
	 *
	 * @param   rvalue      const lvalue reference to the String object on
	 *                      the right side of the expression
	 * @return              true if the left value is greater than or equal
	 *                      to the right value; false otherwise
	 */
	bool operator>=(const myStringClass& rvalue) const;


	/**
	 * Validates the passed String object consists only of alphabetical
	 * letters. Prompts for a new input if the string is invalid until a
	 * valid input is entered.
	 *
	 * Alphabetical letters are any of:
	 * a b c d e f g h i j k l m n o p q r s t u v w x y z
	 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	 *
	 * @param   str         const lvalue reference to the String object to
	 *                      validate
	 */
	static void validateUserInput(myStringClass& str);

	/**
	 * Validates the passed String object consist only of decimal digit
	 * characters. Prompts for a new input if the string is invalid until a
	 * valid input is entered.
	 *
	 * Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9
	 *
	 * @param   str         const lvalue reference to the String object to
	 *                      validate
	 */
	static void validateUserInt(myStringClass& str);

private:
	char* userInput; // C string for holding user input.
	int userInputLength;
};

#endif
