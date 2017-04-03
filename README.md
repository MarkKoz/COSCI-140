# CO SCI 140 - Midterm
**Course Title:** C++ Programming II<br/>
**Section:** 7477<br/>
**Instructor:** Luis Flores<br/>
**Semester:** Spring 2017 (2017-02-06 to 2017-06-05)<br/>
**Textbook:** [Gaddis, Tony. _Starting Out with C++ from Control Structures to Objects_. 8th ed.](https://www.pearsonhighered.com/program/Gaddis-Starting-Out-with-C-from-Control-Structures-to-Objects-plus-My-Programming-Lab-with-Pearson-e-Text-Access-Card-Package-8th-Edition/PGM112149.html) (ISBN-13: 978-0133769395)

### Tasks
Develop a program that will teach youngsters basic mathematics: addition, subtraction, multiplication, and division.
* Generates random math problems for the user to answer.
* The user receives a reward for a correct answer and a pentalty for an incorrect answer.
* The user's statistcs need to be recorded into a text file so that the file can be read by the program in the future to retrieve that user's statistics.
* The user should be allowed to see his or her own statistics at any time from the menu of the program.

### Requirements
* Implement the given header files.
* Separate classes for each operator.
	* Ability to generate and display a math problem.
	* Overload the `<<` operator to display the problem.
	* Check if the user's answer is correct.
	* Operands are generated randomly.
	* Addition
	    * Total is an integer >= 0.
        * `Addition.h` and `Addition.cpp`
    * Subtraction
        * Difference is an integer >= 0.
        * `Subtraction.h` and `Subtraction.cpp`
    * Multiplication
        Product is an integer >= 0.
        * `Multiplication.h` and `Multiplication.cpp`
    * Division
        * Quotient is an integer >= 0.
        * `Division.h` and `Division.cpp`
* Track the user's statistics.
    * Create a sepatate text file for every user.
        * File name is the same as the user's name.
        * Check for the extistence of a file with the user's name at the start of the game and, if found, read the statistics.
        * Update the statistics in the file at the end of the game or after every problem.
    * Statistics to track:
        1. User's name
        2. Total correct answers
        3. Total incorrect answers
        4. Total earnings
            * 5¢ is awarded for correct answers.
            * 3¢ is deducted for incorrect answers.
* Validate user inputs.
* `main()` should consist mostly of function calls and not be greater than 100 lines in total.
* Comments.
* Meaningful variable names.

### Prohibitions
* Global variables.
* Infinite loops. Examples:
    * `for(;;)`
    * `while(1)`
    * `while(true)`
    * `do { // code } while(1);`
* `break` to exit loops.
