#include "main.h"

/**
 * puts_half - Prints the second half of a string followed by a new line
 * @str: Pointer to the string to print
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0, i;

	while (str[len] != '\0')
		len++;

	if (len % 2 != 0)
		i = (len + 1) / 2;
	else
		i = len / 2;

	for (; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

