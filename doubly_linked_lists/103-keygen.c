#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	char key[7];
	char *username;
	int len, i, res;
	char *lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);

	/* Character 1: Based on length */
	key[0] = lookup[(len ^ 59) & 63];

	/* Character 2: Sum of ASCII */
	for (i = 0, res = 0; i < len; i++)
		res += username[i];
	key[1] = lookup[(res ^ 79) & 63];

	/* Character 3: Product of ASCII */
	for (i = 0, res = 1; i < len; i++)
		res *= username[i];
	key[2] = lookup[(res ^ 85) & 63];

	/* Character 4: Highest ASCII value */
	res = 0;
	for (i = 0; i < len; i++)
		if (username[i] > res)
			res = username[i];
	srand(res ^ 14);
	key[3] = lookup[rand() & 63];

	/* Character 5: Sum of squares */
	for (i = 0, res = 0; i < len; i++)
		res += (username[i] * username[i]);
	key[4] = lookup[(res ^ 239) & 63];

	/* Character 6: Random based on first character */
	for (i = 0, res = 0; i < username[0]; i++)
		res = rand();
	key[5] = lookup[(res ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);

	return (0);
}
