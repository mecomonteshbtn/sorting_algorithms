#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 *                       of integers in ascending order using the Insertion
 *                       sort algorithm
 * @list: doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	node = node->next;
	while (node)
	{
		while (node->prev && node->n < (node->prev)->n)
		{
			tmp = node;
			if (node->next)
				(node->next)->prev = tmp->prev;
			(node->prev)->next = tmp->next;
			node = node->prev;
			tmp->prev = node->prev;
			tmp->next = node;
			if (node->prev)
				(node->prev)->next = tmp;
			node->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
			node = node->prev;
		}
		node = node->next;
	}

}
