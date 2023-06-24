#include "monty.h"

extern bus_t bus;

/**
 * f_swap - adds the positions of the top two elements in the stack
 * @h: Pointer to the head of the stac
 * @count: Line number
 * Return: No return value
 */
void f_swap(stack_t **h, unsigned int count)
{
	stack_t *i;
	int len = 0, aux;

	i = *h;
	while (h)
	{
		i = i->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(h);
		exit(EXIT_FAILURE);
	}
	i = *h;
	aux = i->n;
	i->n = i->next->n;
	i->next->n = aux;
}
