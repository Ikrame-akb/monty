#include "monty.h"

extern bus_t bus;

/**
 * f_pop - prints the top element of the stack
 * @h: pointer to the head of the stack
 * @count: Line number
 * Return: No return value
 */
void f_pop(stack_t **h, unsigned int count)
{
	stack_t *i;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	i = *h;
	*h = i->next;
	free(i);
}
