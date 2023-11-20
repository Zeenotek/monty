#include "main.h"
/**
  *rotr_0 - A function that rotates the stack to the bottom
  *@head: head
  *@number_line: argument
 */

void rotr_0(stack_t **head, __attribute__((unused)) unsigned int number_line)
{
	stack_t *save;

	save = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (save->next)
	{
		save = save->next;
	}
	save->next = *head;
	save->prev->next = NULL;
	save->prev = NULL;
	(*head)->prev = save;
	(*head) = save;
}



/**
  *rotl_- A function that rotates the stack to the top
  *@head: head
  *@number_line: argument
 */
void rotl_(stack_t **head,  __attribute__((unused)) unsigned int number_line)
{
	stack_t *tmp = *head, *ptr;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	ptr = (*head)->next;
	ptr->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = ptr;
}




/**
 * pchar_ - A function prints the char at the top of the stack
 * @head: stack head
 * @number_line: argument
*/
void pchar_(stack_t **head, unsigned int number_line)
{
	stack_t *ptr;

	ptr = *head;
	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (ptr->n > 127 || ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ptr->n);
}

/**
 * swap - A function that adds the top two elements of the stack.
 * @head: head
 * @number_line: augment
*/

void swap(stack_t **head, unsigned int number_line)
{
	stack_t *h;
	int len = 0;
    int ptr;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ptr = h->n;
	h->n = h->next->n;
	h->next->n = ptr;
}


/**
  *nop- A funtion that doesnothing
  *@head: head
  *@number_line: argument
 */
void nop(stack_t **head, unsigned int number_line)
{
	(void) number_line;
	(void) head;
}
