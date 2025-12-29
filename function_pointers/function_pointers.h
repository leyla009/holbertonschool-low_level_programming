#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stdio.h>

/* Function prototypes */

/**
 * print_name - prints a name using a given function pointer
 * @name: the name to print
 * @f: pointer to a function that takes a char * and returns void
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *));

/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @action: pointer to a function that takes an int and returns void
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int));

#endif /* FUNCTION_POINTERS_H */

