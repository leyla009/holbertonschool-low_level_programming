#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything based on a format string
 * @format: List of argument types
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
		while (format[i] == 'c' || format[i] == 'i' ||
		       format[i] == 'f' || format[i] == 's')
		{
			printf("%s", sep);

			if (format[i] == 'c')
				printf("%c", va_arg(args, int));
			if (format[i] == 'i')
				printf("%d", va_arg(args, int));
			if (format[i] == 'f')
				printf("%f", va_arg(args, double));
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str)
					printf("%s", str);
				if (!str)
					printf("(nil)");
			}
			sep = ", ";
			break;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

