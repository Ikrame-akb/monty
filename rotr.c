#include "monty.h"
/**
  *f_rotr- Rotates the stack, moving the top element to the bottom
  *@h: Pointer to the head of the stack
  *@count: Line number
  *Return: No return value
 */
void f_rotr(stack_t **h, __attribute__((unused)) unsigned int count)
{
	stack_t *cpy;

	cpy = *h;
	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *h;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*h)->prev = cpy;
	(*h) = cpy;
}
