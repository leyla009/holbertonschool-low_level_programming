#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	/* 1. Iterate through the array */
	for (i = 0; i < ht->size; i++)
	{
		/* 2. If a list exists at this index, free all its nodes */
		node = ht->array[i];
		while (node != NULL)
		{
			temp = node->next;
			/* Free the duplicated key and value */
			free(node->key);
			free(node->value);
			/* Free the node structure itself */
			free(node);
			node = temp;
		}
	}

	/* 3. Free the array of pointers */
	free(ht->array);
	/* 4. Free the hash table management structure */
	free(ht);
}
