#include "monty.h"
/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @h: stack head
 * @count: line_number
 * Return: no return
 */
void mod(stack_t **h, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	i = *h;
	if (i->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	aux = i->next->n % i->n;
	i->next->n = aux;
	*h = i->next;
	free(i);
}