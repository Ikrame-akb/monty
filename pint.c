#include "monty.h"

extern bus_t bus;

/**
 * f_pint - Prints the value at the top of the stack
 * @h: pointer to the head of the stack
 * @count: Line number
 * Return: No return value
 */
void f_pint(stack_t **h, unsigned int count)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
