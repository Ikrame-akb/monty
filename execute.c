#include "monty.h"

/**
 * parse_line - Parses a line of bytecode into an instruction struct.
 * @line: The line of bytecode to parse
 * Return: A pointer to the parsed instruction struct
 */
instruction_t *parse_line(char *line)
{
	instruction_t *instruction = malloc(sizeof(instruction_t));
	char *opcode = NULL;

	if (!instruction)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		exit(EXIT_FAILURE);
	}

	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
	{
		free(instruction);
		free(line);
		return (NULL);
	}

	if (!instruction->f)
	{
		free(instruction->opcode);
		free(instruction);
		free(line);
		exit(EXIT_FAILURE);
	}

	return (instruction);
}

/**
 * execute_file - Executes a Monty bytecode file line by line.
 * @file_path: The path to the Monty bytecode file
 */
void execute_file(char *file_path)
{
	FILE *file = fopen(file_path, "r");
	char *line = NULL;
	instruction_t *instruction = NULL;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	instruction = parse_line(line);
	if (instruction)
	{
		free(instruction->opcode);
		free(instruction);
	}

	free(line);
	fclose(file);
}

/**
 * main - Entry point of the Monty program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: The exit status of the program
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execute_file(argv[1]);

	return (EXIT_SUCCESS);
}
