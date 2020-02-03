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
	int i = (start - 1), j;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[end])
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * check_sorted - check if array is sorted
 * @array: array
 * @size: size of array
 * Return: 1 or 0
 */

int check_sorted(int array[], size_t size)
{
	unsigned int i;

	if (size == 0 || size == 1)
		return (1);

	for (i = 1; i < size; i++)
		if (array[i - 1] > array[i])
			return (0);
	return (1);
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
	int test_sorted;

	test_sorted = check_sorted(array, size);
	if (test_sorted == 0)
		quick(array, 0, size - 1, size);
}
