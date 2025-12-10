#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for the program 101-crackme
 *
 * Return: Always 0.
 */
int main(void)
{
	int sum = 0;
	int ch;

	srand(time(NULL));

	while (sum < 2645)
	{
		ch = (rand() % 94) + 33; /* printable ASCII range */
		sum += ch;
		putchar(ch);
	}

	/* final character makes total = 2772 */
	putchar(2772 - sum);

	return (0);
}

