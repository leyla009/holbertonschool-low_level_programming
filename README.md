<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Low-Level Programming & Algorithm

This repository houses the projects completed during the **Low-Level Programming & Algorithm** track. The curriculum transitions from basic C syntax to complex data structures and system-level engineering, emphasising memory efficiency and manual resource management.

## Tech Stack

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![Bash](https://img.shields.io/badge/bash-%234EAA25.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)
![Git](https://img.shields.io/badge/git-%23F05032.svg?style=for-the-badge&logo=git&logoColor=white)
![Vim](https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white)

## Project Directory

| Project Code | Description | Key Concepts |
| :--- | :--- | :--- |
| **hello_world** | The entry point | Compilation process, `printf`, `puts` |
| **variables_if_else_while** | Control flow | Loops, conditionals, ASCII logic |
| **functions_nested_loops** | Modularity | Function prototypes, nested loops |
| **more_functions...** | Advanced logic | Logical operators, arithmetic |
| **pointers_arrays_strings** | Memory foundations | Addresses, dereferencing, arrays |
| **recursion** | Functional logic | Call stack, base cases, recursion |
| **argc_argv** | Command line arguments | `argc`, `argv`, CLI interactions |
| **malloc_free** | Dynamic allocation | Heap memory, `malloc`, `free` |
| **more_malloc_free** | Advanced allocation | `realloc`, `exit` statuses, memory safety |
| **structures_typedef** | Custom data types | `struct`, `typedef`, data abstraction |
| **function_pointers** | Execution logic | Pointers to functions, callbacks |
| **variadic_functions** | Flexible arguments | `va_start`, `va_arg`, `va_list` |
| **singly_linked_lists** | Linear data structures | Node traversal, dynamic linking |
| **doubly_linked_lists** | Bi-directional lists | Forward/backward traversal        |
| **file_io** | System calls | `open`, `read`, `write`, `close`, permissions         |
| **hash_tables** | Efficient searching | Hash functions, collision handling         |

## General Requirements

* **Editor:** `vi`, `vim`, or `emacs`.
* **Compilation:** All files are compiled on **Ubuntu 22.04 LTS** using `gcc` with the flags `-Wall -Werror -Wextra -pedantic -std=gnu89`.
* **Style:** All code adheres to the **Betty** style guide.
* **Header Files:** Prototypes for all functions are stored in a `main.h` or project-specific header file.

## Testing & Debugging

To compile and check for memory leaks (crucial for projects like `malloc_free` or `linked_lists`):

```bash
# Compile
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o my_program
```

### Check for memory leaks
valgrind --leak-check=full ./my_program

## Author
**LEYLA KHASPOLADOVA**
GitHub: [@leyla009](https://github.com/leyla009)
