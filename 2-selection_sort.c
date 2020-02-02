#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
*selection_sort-function that sorts an array of integers in ascending
*order using the Selection sort algorithm
*@array: pointer to the first item
*@size:size of the array
*Return:Always success
**/
void selection_sort(int *array, size_t size)
{
size_t i, j = 0;
size_t index;
int min;
for (i = 0; i < size - 1 ; i++)
{
index  = i;
min  =  array[i];
for (j = i + 1; j < size ; j++)
{
if (min > array[j])
{
index = j;
min = array[j];
}
}
if (index != i)
{
array[index] = array[i];
array[i] = min;
print_array(array, size);
}
}
}
