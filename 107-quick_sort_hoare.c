#include "sort.h"

/**
 * _swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_split - Hoare partition scheme implementation for quicksort
 * @array: Array to be sorted
 * @low: Index of the first element in the array
 * @high: Index of the last element in the array
 * @size: Size of the array
 *
 * Return: Returns the position of the last element after sorting
 */
int hoare_split(int *array, int low, int high, int size)
{
	int left = low - 1, right = high + 1;
	int pivot = array[high];

	while (1)
	{
		do {
			left++;
		} while (array[left] < pivot);

		do {
			right--;
		} while (array[right] > pivot);

		if (left >= right)
			return (left);

		_swap(&array[left], &array[right]);
		print_array(array, size);
	}
}

/**
 * quicksort - Quicksort algorithm implementation using Hoare split
 * @array: Array to be sorted
 * @low: Index of the first element in the array
 * @high: Index of the last element in the array
 * @size: Size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t position = 0;

	if (low < high)
	{
		position = hoare_split(array, low, high, size);
		quicksort(array, low, position - 1, size);
		quicksort(array, position, high, size);
	}
}

/**
 * quick_sort_hoare - Prepares the terrain for
 * the quicksort algorithm using Hoare split
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
