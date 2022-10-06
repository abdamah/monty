#include "monty.h"

/**
 * main - Main function
 * @argc: Arguments counter
 * @argv: Arguments vector
 * Return: Default return
 **/

int main(int argc, char *argv[])
{
	char *tokens, *lineptr = NULL;
	unsigned int counter = 0;
	stack_t *head = NULL;
	ssize_t read_file;
	size_t bufsize;
	FILE *fl;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fl = fopen(argv[1], "r");
	if (!fl)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_file = getline(&lineptr, &bufsize, fl)) != -1)
	{
		tokens = strtok(lineptr, LIMITER);
		counter++;
		if (tokens)
			select_func(&head, tokens, counter);

		else if (!tokens)
			continue;

	}
	if (lineptr)
		free(lineptr);
	free_all(&head);
	fclose(fl);
	exit(EXIT_SUCCESS);
}
