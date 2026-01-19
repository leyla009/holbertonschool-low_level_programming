#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: A pointer to the hash table.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element,
 * or NULL if key couldn’t be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* 1. Calculate the index where the key should be */
	index = key_index((const unsigned char *)key, ht->size);

	/* 2. Traverse the linked list at that index */
	node = ht->array[index];
	while (node != NULL)
	{
		/* 3. Check if the keys match exactly */
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	/* 4. If the loop finishes without returning, the key doesn't exist */
	return (NULL);
}
