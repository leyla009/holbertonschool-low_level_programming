#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - checks if string is numeric
 * @s: string
 * Return: 1 if numeric, 0 otherwise
 */
int is_digit(char *s)
{
	int i;

	if (!s || !s[0])
		return (0);

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (0);

	return (1);
}

/**
 * _strlen - returns string length
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * print_error - prints Error and exits
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * init_result - allocates result array
 * @len: size
 * Return: pointer or NULL
 */
int *init_result(int len)
{
	int *result, i;

	result = malloc(sizeof(int) * len);
	if (!result)
		return (NULL);

	for (i = 0; i < len; i++)
		result[i] = 0;

	return (result);
}

/**
 * multiply - multiplies two numbers
 * @num1: first number
 * @num2: second number
 * @result: result array
 * @len1: length of num1
 * @len2: length of num2
 */
void multiply(char *num1, char *num2, int *result, int len1, int len2)
{
	int i, j, n1, n2, carry;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}
}

/**
 * print_result - prints result
 * @result: result array
 * @len: length
 */
void print_result(int *result, int len)
{
	int i = 0;

	while (i < len - 1 && result[i] == 0)
		i++;

	for (; i < len; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len;
	int *result;

	if (argc != 3)
		print_error();

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		print_error();

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = init_result(len);
	if (!result)
		exit(98);

	multiply(num1, num2, result, len1, len2);
	print_result(result, len);

	free(result);
	return (0);
}
