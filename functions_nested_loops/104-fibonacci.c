#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers starting with 1 and 2
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	unsigned long a1 = 1, a2 = 2;           /* first two numbers */
	unsigned long b1 = 0, b2 = 0;           /* high parts */
	unsigned long next1, next2;

	printf("%lu, %lu", a1, a2);

	for (i = 3; i <= 98; i++)
	{
		if (a1 + a2 < a1)  /* overflow will happen */
		{
			/* Use high + low splitting */
			next1 = (a1 + a2) % 1000000000;
			next2 = b1 + b2 + ((a1 + a2) / 1000000000);
		}
		else
		{
			next1 = a1 + a2;
			next2 = b1 + b2;
		}

		if (next2 == 0)
			printf(", %lu", next1);
		else
			printf(", %lu%09lu", next2, next1);

		a1 = a2;
		a2 = next1;
		b1 = b2;
		b2 = next2;
	}

	printf("\n");
	return (0);
}
