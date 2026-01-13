#include <stdio.h>

/**
 * first - function that prints a message before main is executed
 *
 * Description: uses the constructor attribute to run before main()
 */
void __attribute__ ((constructor)) first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
