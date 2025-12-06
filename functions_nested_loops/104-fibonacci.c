#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	unsigned long a = 1, b = 2;
	unsigned long a_h, a_l, b_h, b_l, h, l;

	printf("%lu, %lu", a, b);

	for (i = 3; i <= 92; i++)
	{
		b += a;
		a = b - a;
		printf(", %lu", b);
	}

	a_h = a / 1000000000;
	a_l = a % 1000000000;
	b_h = b / 1000000000;
	b_l = b % 1000000000;

	for (; i <= 98; i++)
	{
		h = a_h + b_h;
		l = a_l + b_l;

		if (l >= 1000000000)
			h++, l -= 1000000000;

		printf(", %lu%09lu", h, l);

		a_h = b_h, a_l = b_l;
		b_h = h, b_l = l;
	}

	printf("\n");
	return (0);
}
