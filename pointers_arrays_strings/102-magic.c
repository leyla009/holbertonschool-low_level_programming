 1  #include <stdio.h>
 2
 3  int main(void)
 4  {
 5      int n;
 6      int a[5];
 7      int *p;
 9      a[2] = 1024;
10      p = &n;
11      /*
12       * write your line of code here...
13       * Remember:
14       * - you are not allowed to use a
15       * - you are not allowed to modify p
16       * - only one statement
17       * - you are not allowed to code anything else than this line of code
18       */
	;
19      *( (int *)(&n - 2) + 2 ) = 98;      
	/* ...so that this prints 98\n */
25      printf("a[2] = %d\n", a[2]);
26      return (0);
27  }
