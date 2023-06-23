#ifndef MONTY_H
#define MONTY_H

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
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

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
	void (*f)(stack_t **s, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_push(stack_t **h, unsigned int number);
void f_pall(stack_t **h, unsigned int number);
void f_pint(stack_t **h, unsigned int number);
int execute(char *content, stack_t **h, unsigned int count, FILE *file);
void free_stack(stack_t *h);
void f_pop(stack_t **h, unsigned int count);
void f_swap(stack_t **h, unsigned int count);
void f_add(stack_t **h, unsigned int count);
void f_nop(stack_t **h, unsigned int count);
void f_sub(stack_t **h, unsigned int count);
void f_div(stack_t **h, unsigned int count);
void f_mul(stack_t **h, unsigned int count);
void f_mod(stack_t **h, unsigned int count);
void f_pchar(stack_t **h, unsigned int count);
void f_pstr(stack_t **h, unsigned int count);
void f_rotl(stack_t **h, unsigned int count);
void f_rotr(stack_t **h, __attribute__((unused)) unsigned int count);
void add_node(stack_t **h, int n);
void addqueue(stack_t **h, int n);
void f_queue(stack_t **h, unsigned int count);
void f_stack(stack_t **h, unsigned int count);

#endif