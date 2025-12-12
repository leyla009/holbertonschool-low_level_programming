#include "main.h"

/**
 * infinite_add - adds two numbers stored as strings
 * @n1: first number
 * @n2: second number
 * @r: buffer for the result
 * @size_r: buffer size
 *
 * Return: pointer to result, or 0 if result can't fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, l, sum = 0, carry = 0;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j--;

	i--;
	j--;

	k = size_r - 1;
	r[k] = '\0';
	k--;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		if (k < 0)
			return (0);

		r[k] = (sum % 10) + '0';
		carry = sum / 10;
		k--;
	}

	k++;

	/* Shift result to beginning if needed */
	for (l = 0; r[k + l] != '\0'; l++)
		r[l] = r[k + l];
	r[l] = '\0';

	return (r);
}

