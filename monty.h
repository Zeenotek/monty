#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct point_t - variables -args, file, line content
 * @arg: argument
 * @file: pointer to monty file
 * @content: argument
 * @ptr: flag change
 */
typedef struct point_t
{
	FILE *file;
	char *content;
    char *arg;
	int ptr;
}  bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int operation(char *point, stack_t **head, unsigned int count, FILE *find);
void addnode(stack_t **head, int n);
void pchar_(stack_t **head, unsigned int counter);
void rotl_(stack_t **head, unsigned int number_line);
void free_stack(stack_t *head);
void pop_(stack_t **head, unsigned int number_line);
void pint_(stack_t **head, unsigned int number_line);
void pall(stack_t **head, unsigned int number_line);
void push_(stack_t **head, unsigned int number_line);
void swap(stack_t **head, unsigned int number_line);
void mod(stack_t **head, unsigned int number_line);
void queueadd(stack_t **head, int n);
void pstr_(stack_t **head, unsigned int number_line);
void div_(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int number_line);
void nop(stack_t **head, unsigned int number_line);
void add(stack_t **head, unsigned int number_line);
void mul(stack_t **head, unsigned int number_line);
void free_list(stack_t **h);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void rotr_0(stack_t **head, __attribute__((unused)) unsigned int counter);
char  *clean_line(char *content);
ssize_t getstdin(char **lineptr, int file);
#endif
