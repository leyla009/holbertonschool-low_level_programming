#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: full string
 * @needle: substring to find
 *
 * Return: pointer to beginning of located substring,
 *         or NULL if substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j;

	if (*needle == '\0')
		return (haystack);

	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			j++;
		}

		if (needle[j] == '\0')
			return (&haystack[i]);

		i++;
	}

	return (0);
}

