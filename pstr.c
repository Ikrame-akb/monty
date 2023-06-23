#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @h: Pointer to the stack head
 * @count: Line number
 * Return: No return value
 */
void f_pstr(stack_t **h, unsigned int count)
{
	stack_t *i;
	(void)count;

	i = *h;
	while (i)
	{
		if (i->n > 127 || i->n <= 0)
		{
			break;
		}
		printf("%c", i->n);
		i = i->next;
	}
	printf("\n");
}
