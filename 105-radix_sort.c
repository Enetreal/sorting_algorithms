#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - Finds the maximum number in an array
 * @array: The array
 * @size: Size of the array
 * Return: Maximum number
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countingSort - Sorts an array using counting sort
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: Exponent for the current significant digit
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i != (size_t)-1; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
	}
}
