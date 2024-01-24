#include "sort.h"
#include <stdio.h>

/**
 * print_range - Prints a range of elements in the array
 * @array: Array to print
 * @start: Start index of the range
 * @end: End index of the range
 */
void print_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * swap_elements - Swaps two elements in the array
 * @array: Array
 * @i: Index of the first element
 * @j: Index of the second element
 * @ascending: Sorting direction flag (1 for ascending, 0 for descending)
 */
void swap_elements(int *array, int i, int j, int ascending)
{
	int temp;

	if (ascending == (array[i] > array[j]))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * bitonic_merge - Performs bitonic merge operation on a sequence
 * @array: Array to sort
 * @low: Starting index of the sequence
 * @size: Size of the sequence
 * @ascending: Sorting direction flag (1 for ascending, 0 for descending)
 * @total_size: Total size of the array
 */
void bitonic_merge(int *array, int low, int size, int ascending,
		const int total_size)
{
	int u = low, v = size;

	if (size > 1)
	{
		v = size / 2;
		for (u = low; u < low + v; u++)
			swap_elements(array, u, u + v, ascending);

		bitonic_merge(array, low, v, ascending, total_size);
		bitonic_merge(array, low + v, v, ascending, total_size);
	}
}

/**
 * recursive_sort - Recursively runs the bitonic sort algorithm
 * @array: Array to sort
 * @low: Starting index
 * @size: Size of the array
 * @ascending: Sorting direction flag (1 for ascending, 0 for descending)
 * @total_size: Total size of the array
 */
void recursive_sort(int *array, int low, int size,
		int ascending, const int total_size)
{
	int v = size;

	if (size > 1)
	{
		if (ascending == 1)
			printf("Merging [%d/%d] (UP):\n", size, total_size);
		if (ascending == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, total_size);
		print_range(array, low, low + v - 1);

		v = size / 2;
		recursive_sort(array, low, v, 1, total_size);
		recursive_sort(array, low + v, v, 0, total_size);

		bitonic_merge(array, low, size, ascending, total_size);

		if (ascending == 1)
			printf("Result [%d/%d] (UP):\n", size, total_size);
		if (ascending == 0)
			printf("Result [%d/%d] (DOWN):\n", size, total_size);
		print_range(array, low, low + 2 * v - 1);
	}
}

/**
 * bitonic_sort - Runs the bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	int ascending = 1;
	const int total_size = (int)size;

	if (size < 2 || !array)
		return;

	recursive_sort(array, 0, (int)size, ascending, total_size);
}
