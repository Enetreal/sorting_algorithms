#include <stdio.h>
#include <stdlib.h>

/* Doubly linked list node structure */
typedef struct listint_s {
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function to swap two nodes in a doubly linked list */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2) {
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	printf("Result: ");
	listint_t *current = *list;
	while (current != NULL) {
		printf("%d ", current->n);
		current = current->next;
	}
	printf("\n");
}

/* Function to perform insertion sort on a doubly linked list */
void insertion_sort_list(listint_t **list) {
	if (*list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL) {
		listint_t *insertion_point = current;

		while (insertion_point->prev != NULL && insertion_point->n < insertion_point->prev->n) {
			swap_nodes(list, insertion_point->prev, insertion_point);
			insertion_point = insertion_point->prev;
		}

		current = current->next;
	}
}

/* Example usage */
int main() {
	listint_t *list = NULL;
	listint_t *new_node;

	/* Sample list creation */
	for (int i = 5; i >= 1; i--) {
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		new_node->n = i;
		new_node->next = list;
		new_node->prev = NULL;
		if (list != NULL) {
			list->prev = new_node;
		}
		list = new_node;
	}

	/* Print original list */
	printf("Original list: ");
	listint_t *current = list;
	while (current != NULL) {
		printf("%d ", current->n);
		current = current->next;
	}
	printf("\n");

	/* Perform insertion sort and print the result at each step */
	insertion_sort_list(&list);

	return 0;
}
