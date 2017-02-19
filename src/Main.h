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
 * @param   length      the length of cstring including NUL
 */
void appendChar(char c, char** cstring, int length);

#endif
