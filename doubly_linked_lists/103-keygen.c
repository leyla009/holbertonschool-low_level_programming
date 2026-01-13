#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a valid key for crackme5 based on a username.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	char *username;
	char *lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char key[7];
	int len, i, res;

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);

	/* 1st char: length XOR 59 */
	key[0] = lookup[(len ^ 59) & 63];

	/* 2nd char: sum of ASCII XOR 79 */
	for (i = 0, res = 0; i < len; i++)
		res += username[i];
	key[1] = lookup[(res ^ 79) & 63];

	/* 3rd char: product of ASCII XOR 85 */
	for (i = 0, res = 1; i < len; i++)
		res *= username[i];
	key[2] = lookup[(res ^ 85) & 63];

	/* 4th char: max ASCII char XOR 14 */
	res = 0;
	for (i = 0; i < len; i++)
		if (username[i] > res)
			res = username[i];
	srand(res ^ 14);
	key[3] = lookup[rand() & 63];

	/* 5th char: sum of squares of ASCII XOR 239 */
	for (i = 0, res = 0; i < len; i++)
		res += (username[i] * username[i]);
	key[4] = lookup[(res ^ 239) & 63];

	/* 6th char: first char of username loop */
	for (i = 0, res = 0; i < username[0]; i++)
		res = rand();
	key[5] = lookup[(res ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);

	return (0);
}
