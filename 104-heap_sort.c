#include "sort.h"
#include <stdio.h>

/**
 * heapify - Heapifies a subtree rooted at given index
 * @array: Array to be sorted
 * @size: Size of the array
 * @index: Root of the subtree
 * @total_size: Total size of the heap
 */
void heapify(int *array, size_t size, size_t index, size_t total_size)
{
	size_t largest = index;
	size_t left_child = 2 * index + 1;
	size_t right_child = 2 * index + 2;

	if (left_child < total_size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < total_size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != index)
	{
		/* Swap array[index] and array[largest] */
		int temp = array[index];

		array[index] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		/* Swap root (max element) with last element */
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
