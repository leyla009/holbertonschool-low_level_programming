#include <stdio.h>

int main(void)
{
    int a[5];
    int *p = a;

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;

   
    /* This line changes a[2] without using 'a' or comma */
    *(p + 2) = 98;


    /* Print the new value of a[2] */
    printf("a[2] = %d\n", *(p + 2));

    return (0);
}
