 1 #include <stdio.h>
 2  int main(void)
 3 {
 4     int n;
 5     int a[5];
 6     int *p;
 7 
 8     a[2] = 1024;
 9     p = &n;
10     /*
11      * write your line of code here...
12      * Remember:
13      * - you are not allowed to use a
14      * - you are not allowed to modify p
15      * - only one statement
16      * - you are not allowed to code anything else than this line of code
17      */
18     *( &a[0] + 2) = 98;
19 
20     /* ...so that this prints 98\n */
21     printf("a[2] = %d\n", a[2]);
22     return (0);
23 }
