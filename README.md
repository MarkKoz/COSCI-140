# CO SCI 140 - Chapter 15 Quiz
**Course Title:** C++ Programming II<br/>
**Section:** 7477<br/>
**Instructor:** Luis Flores<br/>
**Semester:** Spring 2017 (2017-02-06 to 2017-06-05)<br/>
**Textbook:** [Gaddis, Tony. _Starting Out with C++ from Control Structures to Objects_. 8th ed.](https://www.pearsonhighered.com/program/Gaddis-Starting-Out-with-C-from-Control-Structures-to-Objects-plus-My-Programming-Lab-with-Pearson-e-Text-Access-Card-Package-8th-Edition/PGM112149.html) (ISBN-13: 978-0133769395)

### Tasks
1. Prompt a user to enter dimensions for a Circle and a Rectangle.
2. Create a Circle object and a Rectangle object.
3. Demonstrate that each object properly calculates and reports its area.

### Requirements
* Pure abstract class `BasicShape`
    * `public: double getArea()`
        * Returns the value in `area`.
    * `public: void setArea(double a)`
        * Assigns the value of `a` to `area`.
    * `public: virtual void calcArea() = 0`
        * Pure virtual function.
    * `private: double area`
        * Holds the shape's area.
* `class Circle : public BasicShape`
    * `public: Circle(double x, double y, double r)`
        * Sets `centerX`, `centerY`, and `radius` to values passed.
        * Calls overridden `calcArea()`.
    * `public: double getArea()`
        * Returns the value in `area`.
    * `public: double getCenterX()`
        * Returns the value in `centerX`.
    * `public: double getCenterY()`
        * Returns the value in `centerY`.
    * `public: void calcArea()`
        * Calculates the area for the circle and stores the evaluated value into `area`.
        * `area = 3.14159 * radius * radius`
    * `private: double centerX`
        * Holds the x-coordinate for the circle's centre.
    * `private: double centerY`
        * Holds the y-coordinate for the circle's centre.
    * `private: double radius`
        * Holds the circle's radius.
* `class Rectangle : public BasicShape`
    * `public: Rectangle(double l, double w)`
        * Sets `length` and `width` to values passed.
        * Calls overridden `calcArea()`.
    * `public: double getArea()`
        * Returns the value in `area`.
    * `public: double getLength()`
        * Returns the value in `length`.
    * `public: double getWidth()`
        * Returns the value in `width`.
    * `public: void calcArea()`
        * Calculates the area for the rectangle and stores the evaluated value into `area`.
        * `area = length * width`
    * `private: double length`
        * Holds the length of the rectangle.
    * `private: double width`
        * Holds the width of the rectangle.
* Validate user inputs to be doubles > 0.

### Prohibitions
* Global variables.
* Infinite loops. Examples:
    * `for(;;)`
    * `while(1)`
    * `while(true)`
    * `do { // code } while(1);`
* `break` to exit loops.
* Code found on the internet.
