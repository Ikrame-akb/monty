#include "monty.h"

extern bus_t bus;

/**
 * execute - executes the opcode
 * @s: head linked list - stack
 * @count: line_counter
 * @f: poiner to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **s, unsigned int count, FILE *file)
{
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (op[i].opcode && op)
	{
		if (strcmp(op, op[i].opcode) == 0)
		{
			op[i].f(s, count);
			return (0);
		}
		i++;
	}
	if (op && op[i]opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(s);
		exit(EXIT_FAILURE); }
	return (1);
}
