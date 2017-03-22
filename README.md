# CO SCI 140 - Chapter 14 Quiz
**Course Title:** C++ Programming II<br/>
**Section:** 7477<br/>
**Instructor:** Luis Flores<br/>
**Semester:** Spring 2017 (2017-02-06 to 2017-06-05)<br/>
**Textbook:** [Gaddis, Tony. _Starting Out with C++ from Control Structures to Objects_. 8th ed.](https://www.pearsonhighered.com/program/Gaddis-Starting-Out-with-C-from-Control-Structures-to-Objects-plus-My-Programming-Lab-with-Pearson-e-Text-Access-Card-Package-8th-Edition/PGM112149.html) (ISBN-13: 978-0133769395)

### Tasks
1. Given the files `Main.cpp`and `Date.h`, implement the `Date` class in a new file named `DateImp.cpp`.

### Requirements
* `class Date`

    | Operator | Name                         | Description                                        |
    |----------|------------------------------|----------------------------------------------------|
    | `++`     | Increment (Prefix & Postfix) | Increments `day`.                                  |
    | `--`     | Decrement (Prefix & Postfix) | Decrements `day`.                                  |
    | `-`      | Subtraction                  | Calculates the number of days between two dates.   |
    | `<<`     | Stream Insertion             | Formats the date like so: January 1, 1900          |
    | `>>`     | Stream Extraction            | Prompts the user for a date to store.              |

    * Detect and handle the following conditions accordingly:
        * When a date is set to the last day of the month and incremented, it should become the first day of the following month.
        * When a date is set to December 31 and incremented, it should become January 1 of the following year.
        * When a date is set to the first day of the month and decremented, it should become the last day of the previous month.
        * When a date is set to January 1 and decremented, it should become December 31 of the previous year.
    * Input validation for `>>`.
        * Invalid dates: 13/45/2014
        * Valid year range: [1900,9999]

### Prohibitions
* Global variables.
* Infinite loops. Examples:
    * `for(;;)`
    * `while(1)`
    * `while(true)`
    * `do { // code } while(1);`
* `break` to exit loops.
