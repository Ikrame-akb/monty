#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *filename;
	char *line = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	line_number++;
	instruction = get_instruction(line);
	if (instruction.opcode != NULL)
	execute_instruction(&stack, &instruction, line_number);

	free_stack(&stack);
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
