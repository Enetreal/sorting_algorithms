#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                        the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		key = current->prev;

		while (key && key->n > current->n)
		{
			if (key->prev)
				key->prev->next = current;
			if (current->next)
				current->next->prev = key;

			key->next = current->next;
			current->prev = key->prev;

			current->next = key;
			key->prev = current;

			if (!current->prev)
				*list = current;

			print_list(*list);

			key = current->prev;
		}
		current = current->next;
	}
}