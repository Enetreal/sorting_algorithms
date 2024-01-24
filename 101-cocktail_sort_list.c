#include "sort.h"
/**
 *swap_nodes - helper function that swaps 2 nodes in a doubly-linked list
 *@a: first node
 *@b: second node
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
/**
 *tail_reversal- helper function that sorts from the tail back
 *
 *@head: head
 *@tail: tail
 *@list: initial head of the list
 *Return: list head
 */
listint_t *tail_reversal(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_nodes(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);

		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}


/**
 *cocktail_sort_list - sorts linked list using cocktail shaker sort
 *@list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *length;
	int u = 0, v = 0, swapped = 1;

	if (!list || !*list)
		return;

	length = *list;
	for (u = 0; length; u++)
	{
		length = length->next;
	}
	if (u < 2)
		return;
	head = *list;
	while (v < u)
	{
		swapped = 0;
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(head, head->next);
				swapped++;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;

			if (head->next == NULL)
				tail = head;
		}
		head = tail_reversal(head, tail, *list);
		*list = head;
		v++;
	}
}
