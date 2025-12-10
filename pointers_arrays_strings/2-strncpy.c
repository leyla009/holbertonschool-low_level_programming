#include "main.h"

/**
 * _strncpy - Copies at most n bytes of a string from src to dest
 * @dest: Destination buffer
 * @src: Source string
 * @n: Maximum number of bytes to copy from src
 *
 * Return: Pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	/* If src is shorter than n, pad dest with null bytes */
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
