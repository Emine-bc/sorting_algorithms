#include "sort.h"

/**
 * swap - swap two elements of array
 * @a: first element
 * @b: second element
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - takes last element as pivot and divide
 * @array: array
 * @start: starting index
 * @end: ending index
 * @size: size of array
 * Return: left or right position
 */

int partition(int array[], int start, int end, size_t size)
{
	int pivot = array[end];
	int i = (start - 1);

	for (int j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[end]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick - quick recursion
 * @array: array
 * @start: satrting index
 * @end: ending index
 * @size: size of array
 */

void quick(int array[], int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quick(array, start, pivot - 1, size);
		quick(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - calls the fucntion quick
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	quick(array, 0, size - 1, size);
}
