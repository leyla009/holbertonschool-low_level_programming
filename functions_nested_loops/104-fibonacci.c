#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	unsigned long a = 1, b = 2, a_high, a_low, b_high, b_low;
	unsigned long high, low;

	printf("%lu, %lu", a, b);

	/* First 92 numbers fit in unsigned long */
	for (i = 3; i <= 92; i++)
	{
		b = a + b;
		a = b - a;
		printf(", %lu", b);
	}

	/* Split for big numbers starting at 93 */
	a_high = a / 1000000000;
	a_low  = a % 1000000000;
	b_high = b / 1000000000;
	b_low  = b % 1000000000;

	for (; i <= 98; i++)
	{
		high = a_high + b_high;
		low = a_low + b_low;

		if (low >= 1000000000)
		{
			low -= 1000000000;
			high++;
		}

		printf(", %lu%09lu", high, low);

		a_high = b_high;
		a_low = b_low;
		b_high = high;
		b_low = low;
	}

	printf("\n");
	return (0);
}
