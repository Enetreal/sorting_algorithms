#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge(int *array, int *auxiliary, size_t start, size_t mid, size_t end);

/**
 * merge - Merges two subarrays in ascending order.
 * @array: The main array containing subarrays to be merged.
 * @auxiliary: A temporary array to store the merged subarrays.
 * @start: The starting index of the first subarray.
 * @mid: The ending index of the first subarray (exclusive).
 * @end: The ending index of the second subarray.
 */

void merge(int *array, int *auxiliary, size_t start, size_t mid, size_t end)
{
	size_t left = start, right = mid, merged_index = start;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (left < mid && right < end)
	{
		if (array[left] <= array[right])
		{
			auxiliary[merged_index] = array[left];
			left++;
		}
		else
		{
			auxiliary[merged_index] = array[right];
			right++;
		}
		merged_index++;
	}

	while (left < mid)
	{
		auxiliary[merged_index] = array[left];
		left++;
		merged_index++;
	}

	while (right < end)
	{
		auxiliary[merged_index] = array[right];
		right++;
		merged_index++;
	}

	for (merged_index = start; merged_index < end; merged_index++)
	{
		array[merged_index] = auxiliary[merged_index];
	}

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_recursive - Recursively divides and merges the array.
 * @array: The main array to be sorted.
 * @auxiliary: A temporary array for merging subarrays.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 */


void merge_sort_recursive(int *array, int *auxiliary, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
	{
		return;
	}

	mid = start + (end - start) / 2;

	merge_sort_recursive(array, auxiliary, start, mid);
	merge_sort_recursive(array, auxiliary, mid, end);
	merge(array, auxiliary, start, mid, end);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *auxiliary_array;

	if (array == NULL || size < 2)
	{
		return;
	}

	auxiliary_array = malloc(sizeof(*auxiliary_array) * size);
	if (auxiliary_array == NULL)
	{
		return;
	}

	merge_sort_recursive(array, auxiliary_array, 0, size);

	free(auxiliary_array);
}
