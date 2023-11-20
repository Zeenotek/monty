#include "main.h"
/**
* operation - A function that executes opcode
* @head: head linked list of the stack
* @count: argument
* @find: monty file to pinter
* @point: line
* Return: noting
*/

int operation(char *point, stack_t **head, unsigned int count, FILE *find)
{
	instruction_t arr[] = {
				{"push", push_},
                {"pall", pall}, 
                {"pint", pint_},
				{"pop", pop_},
				{"add", add},
				{"nop", nop},
                {"swap", swap},
				{"sub", sub},
				{"div", div_},
				{"mul", mul},
				{"mod", mod},
				{"pchar", pchar_},
				{"pstr", pstr_},
				{"rotl", rotl_},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *ptr;

	ptr = strtok(point, " \n\t");
	if (ptr && ptr[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (arr[i].opcode && ptr)
	{
		if (strcmp(ptr, arr[i].opcode) == 0)
		{	arr[i].f(head, count);
			return (0);
		}
		i++;
	}
	if (ptr && arr[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, ptr);
		fclose(find);
		free(point);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	return (1);
}
