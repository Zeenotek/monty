#include "main.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *ptr;

	ptr = head;
	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}

/**
 * free_list - A function that frees a doubly linked list
 * @h: pointer to head of list
 */

void free_list(stack_t **h)
{
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
