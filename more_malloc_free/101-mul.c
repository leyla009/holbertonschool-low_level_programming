#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if string is numeric, 0 otherwise
 */
int is_digit(char *s)
{
	int i;

	if (s == NULL || s[0] == '\0')
		return (0);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * print_error - prints Error and exits with status 98
 */
void print_error(void)
{
	char *error = "Error\n";
	int i;

	for (i = 0; error[i] != '\0'; i++)
		_putchar(error[i]);

	exit(98);
}

/**
 * print_result - prints the result array
 * @result: result array
 * @len: length of result
 */
void print_result(int *result, int len)
{
	int i = 0;

	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		_putchar('0');

	for (; i < len; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
}

/**
 * multiply - performs the multiplication
 * @num1: first number string
 * @num2: second number string
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
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, i;
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

	result = malloc(sizeof(int) * len);
	if (result == NULL)
		exit(98);

	for (i = 0; i < len; i++)
		result[i] = 0;

	multiply(num1, num2, result, len1, len2);
	print_result(result, len);

	free(result);
	return (0);
}
