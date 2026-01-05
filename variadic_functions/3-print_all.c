#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: format string
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *sep = "";
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(args, int));
				sep = ", ";
				break;
			case 'i':
				printf("%s%d", sep, va_arg(args, int));
				sep = ", ";
				break;
			case 'f':
				printf("%s%f", sep, va_arg(args, double));
				sep = ", ";
				break;
			case 's':
				printf("%s", sep);
				str = va_arg(args, char *);
				while (str == NULL)
				{
					printf("(nil)");
					break;
				}
				while (str != NULL)
				{
					printf("%s", str);
					break;
				}
				sep = ", ";
				break;
			default:
				break;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

