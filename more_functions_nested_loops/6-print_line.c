#include "main.h"

/**
 * print_line - Draws a straight line using '_'
 * @n: Number of times to print the character
 *
 * Return: void
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
		_putchar('_');
	_putchar('\n');
}
