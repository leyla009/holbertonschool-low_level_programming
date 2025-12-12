#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer
 * @size: size of buffer
 */
void print_buffer(char *b, int size)
{
	int offset, i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (offset = 0; offset < size; offset += 10)
	{
		printf("%08x: ", offset);

		/* print hex values */
		for (i = 0; i < 10; i++)
		{
			if (offset + i < size)
				printf("%02x", b[offset + i] & 0xFF);
			else
				printf("  ");

			if (i % 2 == 1)
				printf(" ");
		}

		/* print characters */
		for (j = 0; j < 10 && offset + j < size; j++)
		{
			char c = b[offset + j];

			if (c >= 32 && c <= 126)
				putchar(c);
			else
				putchar('.');
		}

		putchar('\n');
	}
}

