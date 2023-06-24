#include "monty.h"

extern bus_t bus;

/**
  *f_sub- Performs subtraction of the top two elements in the stack
  *@h: Pointer to the head of the stack
  *@count: The line number
  *Return: No return value
 */
void f_sub(stack_t **h, unsigned int count)
{
	stack_t *aux;
	int sus, nodes;

	aux = *h;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(h);
		exit(EXIT_FAILURE);
	}
	aux = *h;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*h = aux->next;
	free(aux);
}
