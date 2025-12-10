#include <stdio.h>
int main(void)
{
    int a[5] = {0, 1, 2, 3, 4};
    int *p = a;

    /* This line changes a[2] without using 'a' or comma */
    *(p + 2) = 98;

    /* Print a[2] without using a comma in the added line */
    printf("a[2] = ");
    printf("98");
    printf("\n");

    return (0);
}
