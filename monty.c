#include "main.h"


bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - an entry to an interprenter monty
 * @argc: argument count
 * @argv: file
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{

	ssize_t read = 1;
	char *contain;
	FILE *find;
	size_t len = 0;
	stack_t *stak = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	find = fopen(argv[1], "r");
	bus.file = find;
	if (!find)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		contain = NULL;
		read = getline(&contain, &len, find);
		bus.content = contain;
		count++;
	if (read > 0)
	{
		operation(contain, &stak, count, find);
	}
	free(contain);
	}
	free_stack(stak);
	fclose(find);
		return (0);
}
