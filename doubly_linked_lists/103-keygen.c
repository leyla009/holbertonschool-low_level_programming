#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char *u = argv[1];
	char *l = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char k[7];
	int len, i, tmp;

	if (argc != 2)
		return (1);

	len = strlen(u);

	/* Character 1: Length check */
	k[0] = l[(len ^ 59) & 63];

	/* Character 2: Sum check */
	for (i = 0, tmp = 0; i < len; i++)
		tmp += u[i];
	k[1] = l[(tmp ^ 79) & 63];

	/* Character 3: Product check */
	for (i = 0, tmp = 1; i < len; i++)
		tmp *= u[i];
	k[2] = l[(tmp ^ 85) & 63];

	/* Character 4: Max char check */
	for (i = 0, tmp = u[0]; i < len; i++)
		if (u[i] > tmp)
			tmp = u[i];
	srand(tmp ^ 14);
	k[3] = l[rand() & 63];

	/* Character 5: Sum of squares check */
	for (i = 0, tmp = 0; i < len; i++)
		tmp += (u[i] * u[i]);
	k[4] = l[(tmp ^ 239) & 63];

	/* Character 6: Random loop check */
	for (i = 0, tmp = 0; i < u[0]; i++)
		tmp = rand();
	k[5] = l[(tmp ^ 229) & 63];

	k[6] = '\0';
	printf("%s", k);
	return (0);
}
