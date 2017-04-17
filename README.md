# CO SCI 140 - Chapter 16 Quiz
**Course Title:** C++ Programming II<br/>
**Section:** 7477<br/>
**Instructor:** Luis Flores<br/>
**Semester:** Spring 2017 (2017-02-06 to 2017-06-05)<br/>
**Textbook:** [Gaddis, Tony. _Starting Out with C++ from Control Structures to Objects_. 8th ed.](https://www.pearsonhighered.com/program/Gaddis-Starting-Out-with-C-from-Control-Structures-to-Objects-plus-My-Programming-Lab-with-Pearson-e-Text-Access-Card-Package-8th-Edition/PGM112149.html) (ISBN-13: 978-0133769395)

### Tasks
Develop a vector template class (almost) named `ArrayOfObjects`. The vector must handle objects of type `Circle` or objects of type `Rectangle`, which means a `Circle` template class and a `Rectangle` template class must also be developed. Therefore three template classes, each with its own nested exception class, need to be developed so that the code in the given `Main.cpp` will run.

### Requirements
* `template<class Item> class ArrayOfObjects`
    * `public: ArrayOfObjects()`
        * `ptrToArrayOfObjects = nullptr;`
    * `public: ArrayOfObjects(int arraySize)`
        * `if (arraySize < 0) throw ErrorAllocatingPointerMemory;`
        * `ptrToArrayOfObjects = new Item[arraySize];`
    * `public: Item& operator[](const int& x)`
        * `return ptrToArrayOfObjects[x];`
    * `public: class ErrorAllocatingPointerMemory`
        * Used to catch potential errors caused by negative values in arraySize.
        * `public: ErrorAllocatingPointerMemory(int val)`
            * `value = val;`
        * `public: int getValue() const`
            * `return value;`
        * `private: int value`
            * Holds the value which caused the exception to be thrown.
    * `private: Item* ptrToArrayOfObjects`
        * Pointer to an array of type `Item`, where `Item` may be `Circle` or `Rectangle`.
* `template<class Item> class Circle`
    * `public: Circle()`
        * `++circleCount;`
        * `circleRadius = 0;`
    * `public: Circle(Item radius)`
        * `if (radius < 0) throw ErrorAllocatingMemory;`
        * `++circleCount;`
        * `circleRadius = radius;`
    * `public: int getCircleCount() const`
        * `return circleCount;`
    * `public: Item getCircleRadius() const`
        * `return circleRadius;`
    * `public: void setCircleRadius(Item radius)`
        * `circleRadius = radius;`
    * `public: class ErrorAllocatingMemory`
        * Used to catch potential errors caused by negative values for the radius of the circle.
        * `public: ErrorAllocatingMemory(Item val)`
            * `value = val;`
        * `public: Item getValue() const`
            * `return value;`
        * `private: Item value`
            * Holds the value which caused the exception to be thrown.
    * `private: static int circleCount`
        * Keeps track of the number of circles.
    * `private: Item circleRadius`
        * Holds the radius of the circle.
* `template<class Item, class Item2> class Rectangle`
    * `public: Rectangle()`
        * `++rectangleCount;`
        * `rectangleWidth = 0;`
        * `rectangleLength = 0;`
    * `public: Rectangle(Item width, Item2 length)`
        * `if (width < 0 || length < 0) throw ErrorAllocatingLengthOrWidth;`
        * `++rectangleCount;`
        * `rectangleWidth = width;`
        * `rectangleLength = length;`
    * `public: int getRectangleCount() const`
        * `return rectangleCount;`
    * `public: Item getRectangleWidth() const`
        * `return rectangleWidth;`
    * `public: Item2 getRectangleLength() const`
        * `return rectangleLength;`
    * `public: void setRectangleWidth(Item width)`
        * `rectangleWidth = width;`
    * `public: void setRectangleLength(Item2 length)`
        * `rectangleLength = length;`
    * `public: class ErrorAllocatingLengthOrWidth`
        * Used to catch potential errors caused by negative values for the width or length of the rectangle.
        * Accounts for length and width being different types.
        * `public: ErrorAllocatingLengthOrWidth(Item val)`
            * `value = val;`
        * `public: Item getValue() const`
            * `return value;`
        * `private: Item value`
            * Holds the value which caused the exception to be thrown.
    * `private: static int rectangleCount`
        * Keeps track of the number of rectangles.
    * `private: Item rectangleWidth`
        * Holds the width of the rectangle.
    * `private: Item2 rectangleLength`
        * Holds the length of the rectangle.

### Prohibitions
* Global variables.
* Infinite loops. Examples:
    * `for(;;)`
    * `while(1)`
    * `while(true)`
    * `do { // code } while(1);`
* `break` to exit loops.
* Code found on the internet.
* STL template classes and functions.
