#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the previously allocated memory
 * @old_size: size of the allocated space for ptr (in bytes)
 * @new_size: new size of the memory block (in bytes)
 *
 * Return: pointer to the reallocated memory, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	char *old_ptr;
	unsigned int i;
	unsigned int limit;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_ptr = ptr;
	limit = (old_size < new_size) ? old_size : new_size;

	for (i = 0; i < limit; i++)
		new_ptr[i] = old_ptr[i];

	free(ptr);

	return (new_ptr);
}

