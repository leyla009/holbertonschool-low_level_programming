#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated copy of a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i;
	unsigned int len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}

