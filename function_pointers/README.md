# Function Pointers

## Description
This project focuses on understanding **function pointers** in C.  
Function pointers allow you to store the address of a function and call it indirectly, enabling flexible code, callbacks, and dynamic behavior.

## Learning Objectives
By the end of this project, you should be able to:

- Explain what a function pointer is
- Declare and initialize function pointers
- Pass function pointers as arguments
- Call functions through pointers
- Implement callbacks using function pointers

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on **Ubuntu 20.04 LTS**
- Programs compiled using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89

- All files end with a new line
- Code must follow **Betty** style
- You are allowed to use the standard library

## Files
| File | Description |
|------|-------------|
| `0-print_name.c` | Implements `print_name` that prints a name using a function pointer |
| `1-array_iterator.c` | Implements `array_iterator` to apply a function to each array element |
| `2-int_index.c` | Implements `int_index` to search for an integer using a comparison function |
| `function_pointers.h` | Header file with all function prototypes for exercises 0-2 |

## Example Usage
```c
print_name("Bob", print_name_as_is);
print_name("Bob Dylan", print_name_uppercase);

Output:

Hello, my name is Bob
Hello, my uppercase name is BOB DYLAN

3-Calc: Simple Calculator Using Function Pointers
Files
File	Description
3-main.c	Main program for the calculator
3-op_functions.c	Implements basic operations (+, -, *, /, %)
3-get_op_func.c	Selects the correct operation function based on the operator
3-calc.h	Header file with struct and function prototypes for the calculator
Usage

Compile the program:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-op_functions.c 3-get_op_func.c -o calc


Run examples:

./calc 1 + 1
# Output: 2

./calc 1024 / 10
# Output: 102

./calc 1024 '%' 98
# Output: 44


Error Handling

Wrong number of arguments → prints Error and exits with status 98

Invalid operator → prints Error and exits with status 99

Division or modulo by 0 → prints Error and exits with status 100

Notes

All programs use Betty coding style

Function pointers are used for flexibility and callbacks

The calculator uses strict constraints:

Maximum of 3 if statements in main

No loops in main

get_op_func uses only one while loop and one if statement

Author

Leyla Khaspoladi
