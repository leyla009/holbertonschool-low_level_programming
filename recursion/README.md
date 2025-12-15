 Overview

This directory contains exercises and projects focused on recursion in C, completed as part of the Holberton School Low-Level Programming curriculum.

Recursion is a programming technique where a function calls itself in order to solve a problem by breaking it down into smaller subproblems. These tasks are designed to strengthen understanding of base cases, recursive cases, and call stack behavior.

 Learning Objectives

By completing the tasks in this directory, I learned how to:

Understand and explain recursion

Identify and implement base cases

Write recursive functions without using loops

Trace recursive calls and the call stack

Avoid infinite recursion

Apply recursion to strings, numbers, and algorithms

 Files Description
File	Description
0-puts_recursion.c	Prints a string followed by a new line using recursion
1-print_rev_recursion.c	Prints a string in reverse using recursion
2-strlen_recursion.c	Returns the length of a string using recursion
3-factorial.c	Returns the factorial of a number using recursion
4-pow_recursion.c	Returns the value of x raised to the power of y using recursion
5-sqrt_recursion.c	Returns the natural square root of a number using recursion
6-is_prime_number.c	Checks if a number is a prime number using recursion

(Files may vary depending on project progress.)

 Requirements

Language: C

Compiler: gcc

Compilation flags:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89

No loops allowed for recursive tasks (unless explicitly stated)

No global variables

Code must follow the Betty style guide

Compilation Example
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 0-main.c 0-puts_recursion.c -o puts_recursion

Run:

./puts_recursion

 Common Pitfalls

Forgetting a base case

Modifying variables incorrectly before the recursive call

Infinite recursion leading to stack overflow

Mixing loops with recursion when not allowed

 Author

Leyla Khaspolad
Holberton School Student

"To understand recursion, you must first understand recursion."
