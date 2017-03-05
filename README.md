# CO SCI 140 - Chapter 11 Quiz
**Course Title:** C++ Programming II<br/>
**Section:** 7477<br/>
**Instructor:** Luis Flores<br/>
**Semester:** Spring 2017 (2017-02-06 to 2017-06-05)<br/>
**Textbook:** [Gaddis, Tony. _Starting Out with C++ from Control Structures to Objects_. 8th ed.](https://www.pearsonhighered.com/program/Gaddis-Starting-Out-with-C-from-Control-Structures-to-Objects-plus-My-Programming-Lab-with-Pearson-e-Text-Access-Card-Package-8th-Edition/PGM112149.html) (ISBN-13: 978-0133769395)

### Tasks
1. Read students' names and test scores from a file.
2. Write to a file each student's name followed by the corresponding test score and letter grade.
3. Write to the same file the highest test score and the names of the students which have that score.

### Requirements
* Store student data in `struct studentType` with four components:
    * `string studentFName`
    * `string studentLName`
    * `int testScore` [0, 100]
    * `char grade`
* An array of 20 elements (assume 20 students) of type `studentType`.
* At least the following functions:
    * Read the students' data into an array.
    * Assign a letter grade to each student.
    * Find the highest test score.
    * Print the names of the students with the highest test score.
* Read data from the given file `Data.txt`.
* Write to a new file `Out.txt`.
    * Name format: `Surname, Forename`; left-justified.
* `main()` should only consist of:
    * Declared variables.
    * Opening of input and output files.
    * Function calls.
* Comments.
* Meaningful or mnemonic variable names.

### Prohibitions
* Global variables.
* Infinite loops. Examples:
    * `for(;;)`
    * `while(1)`
    * `while(true)`
    * `do { // code } while(1);`
* `break` to exit loops.
