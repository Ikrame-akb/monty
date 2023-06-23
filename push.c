#include "monty.h"
/**
 * f_push - Adds a node to the stack
 * @h: pointer to the stack head
 * @count: Line number
 * Return: No return value
 */
void f_push(stack_t **h, unsigned int count)
{
	int i, a = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			a++;
		for (; bus.arg[a] != '\0'; a++)
		{
			if (bus.arg[a] > 57 || bus.arg[a] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*h);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}
