#ifndef CH09_QUIZ_MAIN_H
#define CH09_QUIZ_MAIN_H

#include <string>

using namespace std;

/**
 * Ensures that the user's input is an integer >= 0.
 *
 * @param   input       the user's input string
 * @param   sizeVar     the variable in which to store the user's input as an
 *                      integer
 */
void validateInt(string input, int& sizeVar);

/**
 * Dynamically allocates an array of type int and returns a pointer to it.
 *
 * @param   size    the size of the array to be created
 * @return          a pointer to the array created
 */
int* makeArray(int size);

/**
 * Loads a given array with integers of random values, ranging from 1
 * to 100.
 *
 * Uses pointer arithmetic to step through the array.
 *
 * @param   arr     the array into which to load numbers
 * @param   size    the size of the array
 */
void loadNumberData(int* arr, int size);

/**
 * Prints the contents of a given array to the console.
 *
 * Uses pointer arithmetic to step through the array.
 *
 * @param   arr     the array of whose contents to display
 * @param   size    the size of the array
 */
void displayArray(int* arr, int size);

/**
 * Sorts the contents of a given array into ascending order by means of a
 * selection sort algorithm.
 *
 * @param   arr     the array to sort
 * @param   size    the size of the array
 */
void selectionSort(int arr[], int size);

/**
 * Calculates and returns the average of the values in a given array.
 *
 * @param   arr     the array for which to calculate the average
 * @param   size    the size of the array
 * @return          the average
 */
double average(int* arr, int size);

/**
 * Calculates and returns the median of the values in a given array.
 *
 * @param   arr     the array for which to calculate the median
 * @param   size    the size of the array
 * @return          the average
 */
double median(int* arr, int size);

/**
 * Calculates and returns the mode (the value which appears most frequently) of
 * the values in a given array.
 *
 * Returns -1 if no value appears more than once.
 *
 * @param   arr     the array for which to calculate the mode
 * @param   size    the size of the array
 * @return          the average
 */
int mode(int* arr, int size);

#endif
