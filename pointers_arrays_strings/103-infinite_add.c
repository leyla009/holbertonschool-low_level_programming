#include "main.h"

/**
 * infinite_add - adds two numbers stored as strings
 * @n1: first number
 * @n2: second number
 * @r: buffer where the result will be stored
 * @size_r: size of buffer r
 *
 * Return: pointer to result, or 0 if result cannot fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = size_r - 2, carry = 0, sum;

	/* find lengths */
	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;

	i--, j--;

	/* null terminate result */
	if (size_r < 2)
		return (0);
	r[size_r - 1] = '\0';

	/* add digits from right to left */
	while (i >= 0 || j >= 0 || carry)
	{
		if (k < 0)
			return (0);

		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		r[k--] = (sum % 10) + '0';
		carry = sum / 10;
	}

	/* shift result */
	return (r + k + 1);
}
