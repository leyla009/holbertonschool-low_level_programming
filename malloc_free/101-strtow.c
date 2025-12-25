#include "main.h"
#include <stdlib.h>

/**
 * word_count - counts the number of words in a string
 * @str: input string
 *
 * Return: number of words
 */
int word_count(char *str)
{
	int count = 0, i = 0;

	if (str == NULL)
		return (0);

	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

/**
 * word_len - returns the length of a word starting at str
 * @str: input string
 *
 * Return: length of the word
 */
int word_len(char *str)
{
	int len = 0;

	while (str[len] && str[len] != ' ')
		len++;

	return (len);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: pointer to array of words, or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, wc, wl;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);

	k = 0;
	while (str[i] && k < wc)
	{
		if (str[i] != ' ')
		{
			wl = word_len(&str[i]);
			words[k] = malloc(sizeof(char) * (wl + 1));
			if (words[k] == NULL)
			{
				for (j = 0; j < k; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}
			for (j = 0; j < wl; j++)
				words[k][j] = str[i + j];
			words[k][wl] = '\0';
			k++;
			i += wl;
		}
		else
			i++;
	}

	words[k] = NULL;
	return (words);
}

