# More Functions and Nested Loops

This project covers:
- How to use nested loops effectively
- How to use and create header files
- How to write your own functions
- How to test functions with custom `main` files
- Practical use of prototypes
- Working with ASCII values

## Files

### 1-isdigit.c
Function that checks whether a character is a digit (0 through 9).

**Prototype:**  
`int _isdigit(int c);`

Returns:
- `1` if `c` is a digit (`'0'` to `'9'`)
- `0` otherwise

### main.h
Header file containing function prototypes for the project.

### 1-main.c (provided for testing)
Used to test the `_isdigit` function.

## Compilation

Use the following to compile:

```
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-isdigit.c -o 1-isdigit
```

## Example Output

```
0: 1
a: 0
```
