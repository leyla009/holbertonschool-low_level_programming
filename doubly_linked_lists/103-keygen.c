#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char key[7];
	char *username = argv[1];
	char *lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int len, i, res;

	if (argc != 2)
		return (1);

	len = strlen(username);

	/* Char 0: length XOR 59 */
	key[0] = lookup[(len ^ 59) & 63];

	/* Char 1: sum XOR 79 */
	for (i = 0, res = 0; i < len; i++)
		res += username[i];
	key[1] = lookup[(res ^ 79) & 63];

	/* Char 2: product XOR 85 */
	for (i = 0, res = 1; i < len; i++)
		res *= username[i];
	key[2] = lookup[(res ^ 85) & 63];

	/* Char 3: max char seed */
	res = 0;
	for (i = 0; i < len; i++)
		if (username[i] > res)
			res = username[i];
	srand(res ^ 14);
	key[3] = lookup[rand() & 63];

	/* Char 4: sum of squares XOR 239 */
	for (i = 0, res = 0; i < len; i++)
		res += (username[i] * username[i]);
	key[4] = lookup[(res ^ 239) & 63];

	/* Char 5: first char loop */
	for (i = 0, res = 0; i < username[0]; i++)
		res = rand();
	key[5] = lookup[(res ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);

	return (0);
}
