#include "main.h"
#include <stdlib.h>

/**
 * _isdigit - checks if a string contains only digits
 * @s: string
 *
 * Return: 1 if digits, 0 otherwise
 */
int _isdigit(char *s)
{
	int i = 0;

	if (!s || !s[0])
		return (0);

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns length of string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_error - prints Error
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
}

/**
 * multiply - multiplies two numbers
 * @n1: first number
 * @n2: second number
 */
void multiply(char *n1, char *n2)
{
	int len1 = _strlen(n1), len2 = _strlen(n2);
	int len = len1 + len2, i, j, carry, d1, d2;
	int *res = malloc(sizeof(int) * len);

	if (!res)
		return;

	for (i = 0; i < len; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		d1 = n1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			d2 = n2[j] - '0';
			carry += res[i + j + 1] + d1 * d2;
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		res[i + j + 1] += carry;
	}

	i = 0;
	while (i < len && res[i] == 0)
		i++;

	if (i == len)
		_putchar('0');

	for (; i < len; i++)
		_putchar(res[i] + '0');

	_putchar('\n');
	free(res);
}

/**
 * main - entry point
 */
int main(int argc, char **argv)
{
	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		print_error();
		return (98);
	}

	multiply(argv[1], argv[2]);
	return (0);
}
