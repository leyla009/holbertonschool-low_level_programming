#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char *username;
	char *lookup = "A-Za-z0-9+/"; /* Common lookup table for this task */
	int len, i, sum;
	char key[7];

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);

	/* 1st character: Checksum of length */
	key[0] = lookup[(len ^ 59) & 63];

	/* 2nd character: Sum of ASCII values */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += username[i];
	key[1] = lookup[(sum ^ 79) & 63];

	/* 3rd character: Product of ASCII values */
	sum = 1;
	for (i = 0; i < len; i++)
		sum *= username[i];
	key[2] = lookup[(sum ^ 85) & 63];

	/* 4th character: Highest ASCII value */
	sum = username[0];
	for (i = 0; i < len; i++)
		if (username[i] > sum)
			sum = username[i];
	srand(sum ^ 14);
	key[3] = lookup[rand() & 63];

	/* 5th character: Sum of squares of ASCII values */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += (username[i] * username[i]);
	key[4] = lookup[(sum ^ 239) & 63];

	/* 6th character: Random-based character from first char */
	for (i = 0, sum = 0; i < username[0]; i++)
		sum = rand();
	key[5] = lookup[(sum ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);

	return (0);
}
