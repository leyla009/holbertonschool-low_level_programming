#include "main.h"
#include <stdlib.h>

/**
 * total_length - calculates total length of all arguments plus '\n'
 * @ac: argument count
 * @av: argument vector
 *
 * Return: total number of characters needed
 */
int total_length(int ac, char **av)
{
	int i, j, len = 0;

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			len++;
			j++;
		}
		len++; /* for '\n' */
	}

	return (len);
}

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k;
	int len;

	if (ac == 0 || av == NULL)
		return (NULL);

	len = total_length(ac, av);

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
			str[k++] = av[i][j++];
		str[k++] = '\n';
	}

	str[k] = '\0';
	return (str);
}
