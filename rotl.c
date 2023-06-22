#include "monty.h"
/**
  *f_rotl- Rotates the stack, moving the bottom element to the top
  *@h: Pointer to the head of the stack
  *@count: Line number
  *Return: No return vaoue
 */
void f_rotl(stack_t **h,  __attribute__((unused)) unsigned int count)
{
	stack_t *tmp = *h, *aux;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	aux = (*h)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = tmp;
	(*h) = aux;
}
