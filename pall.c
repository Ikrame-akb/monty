#include "monty.h"
/**
 * pall - prints the stack
 * @h: stack head
 * @count: no used
 */
void pall(stack_t **h, unsigned int count)
{
	stack_t *i;
	(void)count;

	i = *h;
	if (i == NULL)
		return;
	while (i)
	{
		printf("%d\n", i->n);
		i = i->next;
	}
}
