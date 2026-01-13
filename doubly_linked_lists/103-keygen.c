#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, 1 on failure.
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

	/* 1: Length XOR 59 */
	key[0] = lookup[(len ^ 59) & 63];

	/* 2: Sum of chars XOR 79 */
	res = 0;
	for (i = 0; i < len; i++)
		res += username[i];
	key[1] = lookup[(res ^ 79) & 63];

	/* 3: Product of chars XOR 85 */
	res = 1;
	for (i = 0; i < len; i++)
		res *= username[i];
	key[2] = lookup[(res ^ 85) & 63];

	/* 4: Max char search and srand seed */
	res = 0;
	for (i = 0; i < len; i++)
	{
		if (username[i] > res)
			res = username[i];
	}
	srand(res ^ 14);
	key[3] = lookup[rand() & 63];

	/* 5: Sum of squares XOR 239 */
	res = 0;
	for (i = 0; i < len; i++)
		res += (username[i] * username[i]);
	key[4] = lookup[(res ^ 239) & 63];

	/* 6: Random loop based on the FIRST character */
	res = 0;
	for (i = 0; i < username[0]; i++)
		res = rand();
	key[5] = lookup[(res ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);

	return (0);
}
