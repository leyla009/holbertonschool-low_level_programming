#include "hash_tables.h"

/**
 * key_index - Gives the index of a key.
 * @key: The key to get the index for.
 * @size: The size of the array of the hash table.
 *
 * Return: The index at which the key/value pair should be stored.
 *
 * Description: Uses the djb2 algorithm to calculate the hash,
 * then uses modulo to fit it within the array size.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	if (size == 0)
		return (0);

	/* 1. Calculate the hash using djb2 */
	hash = hash_djb2(key);

	/* 2. Calculate the index within the range [0, size-1] */
	return (hash % size);
}
