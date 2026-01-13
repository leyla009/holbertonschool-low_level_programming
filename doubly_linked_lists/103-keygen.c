#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	char key[7];
	char *u = argv[1];
	char *l = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int len, i, tmp;

	if (argc != 2)
		return (1);

	len = (int)strlen(u);
	/* 1: length XOR 59 */
	key[0] = l[(len ^ 59) & 63];
	/* 2: sum XOR 79 */
	for (i = 0, tmp = 0; i < len; i++)
		tmp += u[i];
	key[1] = l[(tmp ^ 79) & 63];
	/* 3: product XOR 85 */
	for (i = 0, tmp = 1; i < len; i++)
		tmp *= u[i];
	key[2] = l[(tmp ^ 85) & 63];
	/* 4: max char XOR 14 */
	for (i = 0, tmp = 0; i < len; i++)
		if (u[i] > tmp)
			tmp = u[i];
	srand(tmp ^ 14);
	key[3] = l[rand() & 63];
	/* 5: sum of squares XOR 239 */
	for (i = 0, tmp = 0; i < len; i++)
		tmp += (u[i] * u[i]);
	key[4] = l[(tmp ^ 239) & 63];
	/* 6: random loop based on first char XOR 229 */
	for (i = 0, tmp = 0; i < u[0]; i++)
		tmp = rand();
	key[5] = l[(tmp ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
