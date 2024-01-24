#include "sort.h"
#include <stdlib.h>

void counting_sort(int *array, size_t size);


/**
 * counting_sort - Sorts an array of integers using Counting Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void counting_sort(int *array, size_t size)
{
	int max_value, *count_array, index, *sorted_array;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	max_value = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Create a counting array to store the count of each element */
	count_array = malloc((max_value + 1) * sizeof(int));
	if (count_array == NULL)
		return;

	/* Initialize counting array */
	for (index = 0; index <= max_value; index++)
		count_array[index] = 0;

	/* Populate counting array with the count of each element */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Convert count_array[i] to count_array[i] + count_array[i-1] */
	for (index = 1; index <= max_value; index++)
		count_array[index] += count_array[index - 1];

	/* Print the counting array */
	print_array(count_array, max_value + 1);

	/* Update the original array with sorted values */
	sorted_array = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the sorted elements into the original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	/* Print the sorted array */
	/* print_array(array, size);*/

	/* Free allocated memory */
	free(count_array);
	free(sorted_array);
}
