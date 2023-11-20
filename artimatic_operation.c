#include "main.h"

/**
 * add - A function that adds the top two elements of the stack.
 * @head: head
 * @number_line: argument
*/
void add(stack_t **head, unsigned int number_line)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number_line);
		free_list(head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}


/**
 * mul - A function that multiplies the top two elements of the stack.
 * @head: head
 * @number_line: argument
*/

void mul(stack_t **head, unsigned int number_line)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", number_line);
		free_list(head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}


/**
  *sub- A function that sustration
  *@head: head
  *@number_line: argument
 */

void sub(stack_t **head, unsigned int number_line)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}



/**
 * div_ - A function that divides the top two elements of the stack.
 * @head: stack head
 * @number_line: argument
*/

void div_(stack_t **head, unsigned int number_line)
{
	stack_t *ptr;
	int len = 0, num;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = ptr->next->n / ptr->n;
	ptr->next->n = num;
	*head = ptr->next;
	free(ptr);
}

/**
 * mod - a function that perform mod operation
 * @head: head
 * @number_line: argumernt
*/

void mod(stack_t **head, unsigned int number_line)
{
	stack_t *h;
	int len = 0, ptr;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number_line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = h->next->n % h->n;
	h->next->n = ptr;
	*head = h->next;
	free(h);
}
