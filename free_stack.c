#include "monty.h"
/**
 * free_stack - frees a doubly linked list
 * @h: head of the stack
 */
void free_stack(stack_t *h)
{
	stack_t *a;

	a = h;
	while (h)
	{
		a = h->next;
		free(h);
		h = a;
	}
}
