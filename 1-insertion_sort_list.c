#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Insertion sort for list
 * @list: pointer to the list's head
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted_node, *sorted_node, *p;

	unsorted_node = (*list)->next;
	while (unsorted_node != NULL)
	{
		sorted_node = unsorted_node->prev;
		if (unsorted_node->n < sorted_node->n)
		{
			sorted_node->prev = sorted_node;
			sorted_node->next = unsorted_node->next;
			unsorted_node->next = sorted_node;

		}
		
	}
}
