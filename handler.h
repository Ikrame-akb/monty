#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "lists.h"
#include "stackops.h"

/**
 * get - get functins
 * @opcode: intstruction opcode
 * Return: void
 */
__local
void (*get(char *opcode))(stack_t **stack, uint line_number)
{
	instruction_t opt[] = {
		{"pchar", pchar},
		{"rotl", rotl},
		{"rotr", rotr},
		{"pstr", pstr},
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"nop", _nop},
		{"pop", _pop},
		{"add", _add},
		{"sub", _sub},
		{"mod", _mod},
		{"mul", _mul},
		{"div", _div},
		{NULL, NULL} };
	int i;

	for (i = 0; opt[i].opcode; i++)
	{
		if (!strcmp(opcode, opt[i].opcode))
			return (opt[i].f);
	}

	return (NULL);
}

/**
 * handler - main handler
 * @ac: ref main
 * @av: ref main
 * Return: ref main
 */
__local int handler(int ac, char **av)
{
	stack_t *stack = NULL;

	fi(ac != 2) FAIL_ARGNUM;
	s.fp = fopen(av[1], "r");
	fi(!s.fp) FAIL_FILE(av[1]);

	{
		for (s.token = strtok(s.line, s.delim); s.token;)
		{
			if (s.token[0] == '#')
				break;

			if (!strcmp(s.token, "stack"))
			{	s.mode = STACK;
				break;
			}

			if (!strcmp(s.token, "queue"))
			{	s.mode = QUEUE;
				break;
			}
			if (get(s.token))
			{
				fclose(s.fp);
				empty_stack(stack);
			}
			break;
		}
	}
	empty_stack(stack);
	free(s.token);
	fclose(s.fp);
	return (0);
}

#endif
