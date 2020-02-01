#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
* bubble_sort-function that sort that sorts an array of integers
*in ascending order using the Bubble sort algorithm
*@array: pointer to the first item
*@size:size of the array
*Return:Always success
**/
void bubble_sort(int *array, size_t size)
{
size_t i, j = 0;
int temp;
for (; j < size; j++)
{
for (i = 0 ; i < size - 1 ; i++)
{
if (array[i] > array[i + 1])
{
temp = array[i + 1];
array[i + 1] = array[i];
array[i] = temp;
print_array(array, size);
}
}
}
}
