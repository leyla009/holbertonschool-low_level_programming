#include "main.h"

/**
 * print_diagonal - Draws a diagonal line using '\'
 * @n: Number of times to print the diagonal
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int line, space;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (line = 0; line < n; line++)
	{
		for (space = 0; space < line; space++)
			_putchar(' ');
		_putchar('\\');
		_putchar('\n');
	}
}
