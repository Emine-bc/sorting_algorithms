#include "sort.h"
/**
 * counting_sort-a function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 *@array: pointer to the first item
 *@size:size of the array
 *Return:Always success
 **/
void counting_sort(int *array, size_t size)
{
size_t i;
int max = array[0];
int x, al = 0, k;
int *cmp = NULL;
int *copy = NULL;
if (array == NULL)
return;
for (i = 0; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
copy = malloc(sizeof(int) * size);
cmp = malloc(sizeof(int) * (max + 1));
if (cmp == NULL || copy == NULL)
return;
for (i = 0; i < size; i++)
cmp[array[i]] += 1;
for (k = 0; k <= max; k++)
{
x = cmp[k];
cmp[k] += al;
al += x;
}
