#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 * Return: A pointer to the table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * insert_into_sorted_list - Inserts a node into the sorted doubly linked list.
 * @ht: The sorted hash table.
 * @new_node: The node to insert.
 */
void insert_into_sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
		return;
	}
	if (strcmp(new_node->key, ht->shead->key) < 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
		return;
	}
	tmp = ht->shead;
	while (tmp->snext != NULL && strcmp(new_node->key, tmp->snext->key) > 0)
		tmp = tmp->snext;
	new_node->sprev = tmp;
	new_node->snext = tmp->snext;
	if (tmp->snext == NULL)
		ht->stail = new_node;
	else
		tmp->snext->sprev = new_node;
	tmp->snext = new_node;
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 * @value: The value.
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *tmp;
	char *val_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = val_copy;
			return (1);
		}
		tmp = tmp->next;
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(val_copy);
		return (0);
	}
	new_node->key = strdup(key);
	new_node->value = val_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	insert_into_sorted_list(ht, new_node);
	return (1);
}

/**
 * shash_table_get - Retrieves a value from the sorted hash table.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table in order.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	tmp = ht->shead;
	while (tmp)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		first = 0;
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first = 1;

	if (ht == NULL)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		first = 0;
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;
	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}
	free(ht->array);
	free(ht);
}
