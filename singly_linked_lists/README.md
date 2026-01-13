# Singly Linked Lists

A collection of C functions for creating, managing, and manipulating singly linked lists.

## Description
This project focuses on understanding and implementing linked data structures in C. It includes functions for printing lists, calculating lengths, adding nodes at the beginning or end, and freeing list memory.

## Data Structure
```c
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

Requirements

    OS: Ubuntu 20.04 LTS

    Compiler: gcc (flags: -Wall -Werror -Wextra -pedantic -std=gnu89)

    Style: Betty coding style

Files
File	Description
lists.h	Header file containing structures and function prototypes.
0-print_list.c	Prints all elements of a list_t list.
1-list_len.c	Returns the number of elements in a list.
2-add_node.c	Adds a new node at the beginning of the list.
3-add_node_end.c	Adds a new node at the end of the list.
4-free_list.c	Frees a list_t list.

Author

LEYLA KHASPOLAD
