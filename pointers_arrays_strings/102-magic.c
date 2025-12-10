#include <stdio.h>

int main(void)
{
    int a[5] = {0, 1, 2, 3, 4};
    int *p = a;

    /* change a[2] without using 'a' or comma */
    *(p + 2) = 98;

    /* print "a[2] = 98\n" without using comma */
    printf("a[2] = ");
    printf("%d", *(p + 2));
    printf("\n");

    return (0);
}
