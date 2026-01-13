Doubly Linked Lists

A collection of C functions for managing and manipulating doubly linked lists (`dlistint_t`).

Description
This project explores the implementation of doubly linked lists, where each node contains pointers to both the next and the previous elements. This allows for bidirectional traversal and more efficient deletions or insertions compared to singly linked lists.

Data Structure
```c
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

Requirements

    OS: Ubuntu 20.04 LTS

    Compiler: gcc (flags: -Wall -Werror -Wextra -pedantic -std=gnu89)

    Style: Betty coding style

Task List

File	Description
0-print_dlistint.c	Prints all elements of a dlistint_t list.
1-dlistint_len.c	Returns the number of elements in a list.
2-add_dnodeint.c	Adds a new node at the beginning of the list.
3-add_dnodeint_end.c	Adds a new node at the end of the list.
4-free_dlistint.c	Frees a dlistint_t list.
5-get_dnodeint.c	Returns the nth node of a list.
6-sum_dlistint.c	Returns the sum of all data (n) in the list.
7-insert_dnodeint.c	Inserts a node at a given position.
8-delete_dnodeint.c	Deletes a node at a given index.

Author

LEYLA KHASPOLAD
