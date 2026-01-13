#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5.
 * @argc: Number of arguments.
 * @argv: Argument vector.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	char k[7];
	char *u = argv[1];
	char *l = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int len, i, res;

	if (argc != 2)
		return (1);

	len = strlen(u);
	/* 1: Length XOR 59 */
	k[0] = l[(len ^ 59) & 63];
	/* 2: Sum XOR 79 */
	for (i = 0, res = 0; i < len; i++)
		res += u[i];
	k[1] = l[(res ^ 79) & 63];
	/* 3: Product XOR 85 */
	for (i = 0, res = 1; i < len; i++)
		res *= u[i];
	k[2] = l[(res ^ 85) & 63];
	/* 4: Max char search + rand */
	for (i = 0, res = 0; i < len; i++)
		if (u[i] > res)
			res = u[i];
	srand(res ^ 14);
	k[3] = l[rand() & 63];
	/* 5: Sum of squares XOR 239 */
	for (i = 0, res = 0; i < len; i++)
		res += (u[i] * u[i]);
	k[4] = l[(res ^ 239) & 63];
	/* 6: Random loop based on first char XOR 229 */
	for (i = 0, res = 0; i < u[0]; i++)
		res = rand();
	k[5] = l[(res ^ 229) & 63];
	k[6] = '\0';
	printf("%s", k);
	return (0);
}
