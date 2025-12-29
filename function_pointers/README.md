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
| `function_pointers.h` | Header file containing prototypes and necessary includes |

## Example Usage
```c
print_name("Bob", print_name_as_is);
print_name("Bob Dylan", print_name_uppercase);

Output:

Hello, my name is Bob
Hello, my uppercase name is BOB DYLAN

Author

Leyla Khaspolad
