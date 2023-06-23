#include "monty.h"

extern bus_t bus;

/**
 * f_add - adds the top two elements of the stack.
 * @h: stack head
 * @count: line_number
 * Return: no return
 */
void f_add(stack_t **h, unsigned int count)
{
	stack_t *i;
	int len = 0, aux;

	i = *h;
	while (i)
	{
		i = i->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	i = *h;
	aux = i->n + i->next->n;
	i->next->n = aux;
	*h = i->next;
	free(i);
}
