# CO SCI 140 - Chapter 13 Quiz
**Course Title:** C++ Programming II<br/>
**Section:** 7477<br/>
**Instructor:** Luis Flores<br/>
**Semester:** Spring 2017 (2017-02-06 to 2017-06-05)<br/>
**Textbook:** [Gaddis, Tony. _Starting Out with C++ from Control Structures to Objects_. 8th ed.](https://www.pearsonhighered.com/program/Gaddis-Starting-Out-with-C-from-Control-Structures-to-Objects-plus-My-Programming-Lab-with-Pearson-e-Text-Access-Card-Package-8th-Edition/PGM112149.html) (ISBN-13: 978-0133769395)

### Tasks
1. Prompt the user to input 5 integers.
2. Print the largest and smallest integer of the set inputted.

### Requirements
* Store user inputs into a one-dimensional array of type `int`.
    * Assume all integers in the array are unique and distinct.
* `class Integers`
    * `public: setUserEntry()`
        1. Prompts the user to input an integer.
        2. Calls `validate()` to validate that the input is an integer.
            * If not an integer, prompts the user to input a new value.
    * `public: validate()`
        * Validates that a given user input is an integer.
    * `const displayIntegers()`
        * Uses a loop to display the values of the array.
        * No parameters.
    * `getLargestSmallestIntegers()`
        * Displays the largest and smallest integers in the array.
    * Loop in constructor to initialise elements in the array to 0.
* Continue/quit loop in `main()`.
* Submit the following 3 files:
    * `Integers.h`
    * `IntegersImp.cpp`
    * Any-name `.cpp` with `main()`.

### Prohibitions
* Global variables.
* Infinite loops. Examples:
    * `for(;;)`
    * `while(1)`
    * `while(true)`
    * `do { // code } while(1);`
* `break` to exit loops.
