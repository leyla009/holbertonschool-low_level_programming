#include <stdio.h>
int main(void)
{
    int n;
    int a[5];
    int *p;

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;

    p = a;
    /*
     * write your line of code here
     * - you are not allowed to code anything else than this line of code
     */
    *(p + 2) = 98;
    printf("a[2] = %d\n", *(p + 2));

    return (0);
}
