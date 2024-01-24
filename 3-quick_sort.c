#include "sort.h"



/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick Sort.
 * @array: The array of integers.
 * @first: The first index of the array subset.
 * @last: The last index of the array subset.
 * @size: The size of the array.
 * Return: The position of the last element after sorting.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				_swap(array + current, array + finder);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[last])
	{
		_swap(array + current, array + last);
		print_array(array, size);
	}

	return (current);
}

/**
 * quick - Implements the Quick Sort algorithm using Lomuto partition.
 * @array: The array of integers.
 * @first: The first index of the array subset.
 * @last: The last index of the array subset.
 * @size: The size of the array.
 */
void quick(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);
		quick(array, first, position - 1, size);
		quick(array, position + 1, last, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick(array, 0, size - 1, size);
}



#include "sort.h"


/**
 * _swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
