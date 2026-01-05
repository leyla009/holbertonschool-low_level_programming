#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a char
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an int
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str)
		printf("%s", str);
	if (!str)
		printf("(nil)");
}

/**
 * print_all - prints anything
 * @format: format string
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *sep = "";

	struct printer
	{
		char type;
		void (*f)(va_list);
	} printers[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (printers[j].type)
		{
			if (format[i] == printers[j].type)
			{
				printf("%s", sep);
				printers[j].f(args);
				sep = ", ";
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

