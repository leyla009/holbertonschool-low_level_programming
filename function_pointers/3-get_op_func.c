#include "3-calc.h"

/**
 * get_op_func - selects the correct function for the operator
 * @s: the operator passed as argument
 *
 * Return: pointer to the function, or NULL if not found
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL && *(ops[i].op) != *s)
		i++;

	if (ops[i].op != NULL && *(ops[i].op) == *s && *(ops[i].op + 1) == '\0')
		return (ops[i].f);

	return (NULL);
}

