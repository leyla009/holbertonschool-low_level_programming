#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive numbers passed as arguments
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int sum = 0, i, j;
	char *arg;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		arg = argv[i];
		for (j = 0; arg[j]; j++)
		{
			if (!isdigit(arg[j]))
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(arg);
	}

	printf("%d\n", sum);
	return (0);
}

