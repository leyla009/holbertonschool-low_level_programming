#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: bytes to match
 *
 * Return: number of bytes in the initial segment of s
 *         consisting only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i;
	char *a;

	while (*s)
	{
		a = accept;
		i = 0;

		while (*a)
		{
			if (*s == *a)
			{
				i = 1;
				break;
			}
			a++;
		}

		if (!i)
			break;

		count++;
		s++;
	}

	return (count);
}

