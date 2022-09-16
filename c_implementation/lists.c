#include "factors.h"

/**
 * add_node - add a node
 * @tail: tail
 * @n: prime number
 *
 * Return: node
 *
 * Description: Adds a node to the end of a list
 */
prime_t *add_node(prime_t **tail, const unsigned long n)
{
	prime_t *new;

	new = malloc(sizeof(prime_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*tail)
	{
		(*tail)->next = new;
		new->idx = (*tail)->idx + 1;
	}
	else
	{
		new->idx = 0;
	}
	*tail = new;
	return (new);
}

/**
 * free_list - free nodes
 * @head: head of list
 */
void free_list(prime_t *head)
{
	prime_t *temp;

	temp = head;
	while (temp)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

