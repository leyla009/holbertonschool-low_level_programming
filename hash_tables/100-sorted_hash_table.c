#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash table, or NULL on failure.
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
 * insert_sorted - Inserts a node into the sorted doubly linked list of a table.
 * @ht: A pointer to the sorted hash table.
 * @node: The node to insert.
 */
void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
		return;
	}
	if (strcmp(ht->shead->key, node->key) > 0)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		return;
	}
	tmp = ht->shead;
	while (tmp->snext != NULL && strcmp(tmp->snext->key, node->key) < 0)
		tmp = tmp->snext;
	node->snext = tmp->snext;
	node->sprev = tmp;
	if (tmp->snext == NULL)
		ht->stail = node;
	else
		tmp->snext->sprev = node;
	tmp->snext = node;
}

/**
 * shash_table_set - Adds or updates an element in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key (cannot be empty).
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *val_copy;
	unsigned long int index;

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
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(val_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(val_copy);
		free(new);
		return (0);
	}
	new->value = val_copy;
	new->next = ht->array[index];
	ht->array[index] = new;
	insert_sorted(ht, new);
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: A pointer to the sorted hash table.
 * @key: The key looking for.
 *
 * Return: The value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
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
