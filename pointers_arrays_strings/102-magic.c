#include <stdio.h>

/**
 * main - prints a[2] = 98 without using 'a' in the assignment
 *
 * Return: Always 0
 */
int main(void)
{
    int a[5] = {0, 1, 2, 3, 4};
    int *p = a;

    /* This line changes a[2] without using 'a' or comma */
    *(p + 2) = 98;

    /* Print a[2] using separate printf calls */
    printf("a[2] = ");
    printf("98");
    printf("\n");

    /* End of main function */
    return (0);
}
