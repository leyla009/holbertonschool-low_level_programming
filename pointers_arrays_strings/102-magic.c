#include <stdio.h>
int main(void)
{
    int a[5] = {0, 1, 2, 3, 4};
    int *p = a;
    *(p + 2) = 98;
    printf("a[2] = %d\n", *(p + 2));
    return (0);
}
