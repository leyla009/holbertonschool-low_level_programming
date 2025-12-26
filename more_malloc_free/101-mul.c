#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point
 * @argc: count of argv
 * @argv: arguments
 *
 * Return: 0 if successfully completed, otherwise 98
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, i, j, mul, sum, *result, start;

	if (argc != 3)
		printf("Error\n"), exit(98);
	for (i = 1; i < argc; i++)
		for (j = 0; argv[i][j] != '\0'; j++)
			if (argv[i][j] < 48 || argv[i][j] > 57)
				printf("Error\n"), exit(98);

	num1 = argv[1], num2 = argv[2];
	len1 = strlen(num1), len2 = strlen(num2);
	len = len1 + len2;
	result = malloc(sizeof(int) * len);

	if (result == NULL)
		printf("Error\n"), exit(98);
	for (i = 0; i < len; i++)
		result[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}

	start = 0;
	while (start < len && result[start] == 0)
		start++;

	if (start == len)
		putchar('0');
	else
		for (; start < len; start++)
			putchar(result[start] + '0');
	putchar('\n');
	free(result);
	return (0);
}
