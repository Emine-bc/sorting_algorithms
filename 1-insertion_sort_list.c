#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * check_sorted - check if a list is sorted
 * @head: head of list
 * Return: 0 or 1
 */

int check_sorted(listint_t *head)
{
	if (head == NULL || head->next == NULL)
		return (1);

	return (head->n > head->next->n &&
			check_sorted(head->next));
}


/**
 * swap - swap two nodes
 * @unsorted: unsorted node
 * @sorted: sorted node
 * @list: head of list
 */

void swap(listint_t **unsorted, listint_t **sorted, listint_t **list)
{
	if (*sorted == *list)
		*list = *unsorted;
	if ((*sorted)->prev != NULL)
		(*sorted)->prev->next = (*unsorted);
	if ((*unsorted)->next != NULL)
		(*unsorted)->next->prev = (*sorted);
	(*sorted)->next = (*unsorted)->next;
	(*unsorted)->next = (*sorted);
	(*unsorted)->prev = (*sorted)->prev;
	(*sorted)->prev = (*unsorted);
}



/**
 * insertion_sort_list - Insertion sort for list
 * @list: pointer to the list's head
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted_node, *sorted_node;

	if (!list || !(*list) || !(*list)->next)
		return;
	unsorted_node = (*list)->next;
	while (unsorted_node != NULL && check_sorted(*list) != 1)
	{
		sorted_node = unsorted_node->prev;
		if (unsorted_node->n < sorted_node->n)
		{
			swap(&unsorted_node, &sorted_node, &(*list));
			print_list(*list);
			unsorted_node = (*list);
		}
		unsorted_node = unsorted_node->next;
	}
}
