#include "monty.h"
/**
 * f_queue - Prints the element at the top of the queue
 * @h: Pointer to the head of the queue
 * @count: Line number
 * Return: No return value
 */
void f_queue(stack_t **h, unsigned int count)
{
	(void)h;
	(void)count;
	bus.lifi = 1;
}

/**
 * addqueue - Adds a new node to the tail of the stack
 * @i: New value to be added
 * @h: Pointer to the head of the stack
 * Return: No return value
 */
void addqueue(stack_t **h, int i)
{
	stack_t *new_node, *aux;

	aux = *h;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->i = i;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*h = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
