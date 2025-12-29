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

#endif /* FUNCTION_POINTERS_H */                                                                                                                                                   
