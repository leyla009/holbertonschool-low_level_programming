#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to measure
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * _check_palindrome - helper function to check characters recursively
 * @s: string
 * @start: start index
 * @end: end index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int _check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (_check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - returns 1 if a string is a palindrome, 0 otherwise
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len;

	if (*s == '\0')
		return (1);
	len = _strlen_recursion(s);
	return (_check_palindrome(s, 0, len - 1));
}

