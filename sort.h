#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void _swap(int *a, int *b);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, int size);
void quick_sort(int *array, size_t size);

void lomuto_sort(int *array, size_t size, int low, int high);
void recursive_quick_sort(int *array,
		int low, int high, size_t size);
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size);
void quick(int *array, ssize_t first, ssize_t last, int size);

void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void sort_count(int *array, size_t size, int radix, int *output);
int get_maximum(int *array, int size);
void radix_sort(int *array, size_t size);
void merge(int *array, int *auxiliary, size_t start, size_t mid, size_t end);
void merge_sort_recursive(int *array,
		int *auxiliary, size_t start, size_t end);
void merge_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t index, size_t total_size);
void heap_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_range(int *array, int start, int end);
void swap_elements(int *array, int i, int j, int ascending);
void bitonic_merge(int *array, int low, int size, int ascending, const int total_size);
void recursive_sort(int *array, int low, int size, int ascending, const int total_size);
void bitonic_sort(int *array, size_t size);

void r_sort(int *array, int low, int size, int path, const int m);


void recursive_sort(int *array, int low, int size,
		int ascending, const int total_size);
void bitonic_merge(int *array, int low, int size,
		int ascending, const int total_size);
void print_range(int *array, int start, int end);
void print_array(const int *array, size_t size);
void hoare_sort(int *array, size_t size, int low, int high);
int hoare_partition(int *array, size_t size, int low, int high);
void quick_sort_hoare(int *array, size_t size);










#endif /*SORT_H*/
