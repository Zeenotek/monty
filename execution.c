#include "main.h"

/**
 * push_ - A function that add node to the stack
 * @head: head
 * @number_line: argument
*/

void push_(stack_t **head, unsigned int number_line)
{
	int n, i = 0, fl = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		while (bus.arg[i] != '\0')
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
			{
					fl = 1;
			}
			i++; 
		}
		if (fl == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", number_line);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.ptr == 0)
		addnode(head, n);
	else
		queueadd(head, n);
}


/**
 * pall - A function that prints the stack
 * @head: head
 * @number_line: argument
*/

void pall(stack_t **head, unsigned int number_line)
{
	stack_t *ptr;
	(void)number_line;

	ptr = *head;
	if (ptr == NULL)
		return;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}



/**
 * pint_ - A function that prints the top
 * @head: head
 * @number_line: argument
*/

void pint_(stack_t **head, unsigned int number_line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 * pop_ - A functionprints the top
 * @head: head
 * @number_line: argument
*/
void pop_(stack_t **head, unsigned int number_line)
{
	stack_t *ptr;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = ptr->next;
	free(ptr);
	ptr = NULL;
}


/**
 * pstr_ - A function that prints the string starting at the top of the stack
 * @head: head
 * @number_line: argument
*/
void pstr_(stack_t **head, unsigned int number_line)
{
	stack_t *h;
	(void)number_line;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
