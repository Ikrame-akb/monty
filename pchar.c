#include "monty.h"

extern bus_t bus;

/**
 * f_pchar - Prints the character at the top of the stack,
 * followed by a new line
 * @h: Pointer to the head of the stack
 * @count: Line number
 * Return: No return value
 */
void f_pchar(stack_t **h, unsigned int count)
{
	stack_t *i;

	i = *h;
	if (!i)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (i->n > 127 || i->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", i->n);
}
