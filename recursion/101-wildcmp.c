#include "main.h"

/**
 * wildcmp - compares two strings, considering '*' as a wildcard
 * @s1: first string
 * @s2: second string (can contain '*')
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings reach the end, they match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If current char in s2 is '*', it can match zero or more chars in s1 */
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1); /* trailing '*' matches rest of s1 */

		/* Try matching '*' with zero chars or one char at a time */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
		return (wildcmp(s1, s2 + 1));
	}

	/* If chars match, move to next chars */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* Characters don't match and no '*' wildcard */
	return (0);
}

