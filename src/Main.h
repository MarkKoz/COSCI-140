#ifndef CH10_QUIZ_MAIN_H
#define CH10_QUIZ_MAIN_H

/**
 * Prompts the user to input any sequence of characters and returns that input.
 *
 * @return              the user's input as a C string
 */
char* getInput();

/**
 * Appends a character to the end of a C string.
 *
 * @param   c           the character to be appended
 * @param   cstring     a pointer to the C string to which to append
 */
void appendChar(char c, char** cstring);

/**
 * Searches for given characters in a C string and returns their frequencies.
 *
 * @param   cstring     the C string to search
 * @param   chars       a C string of chars for which to search
 * @return              an array of ints representing the frequency for each
 *                      char in the same order as chars
 */
int* getCharFreq(char* cstring, char* chars);

#endif
