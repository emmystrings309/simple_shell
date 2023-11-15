#include "main.h"

/**
 * main - this is the main function\
 * to recieve argument from the user for processing
 *
 * Return: return EXIT_SUCCESS
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];
	char *token;
	size_t i;

	run_script();
	while (1)
	{/* Print shell prompt */
		printf("($) ");
		fflush(stdout);
		/* Read user input */
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break; /* Exit on EOF */
		}
		/* Remove newline character */
		input[strcspn(input, "\n")] = '\0';
		/* Tokenize the input into arguments */
		token = strtok(input, " ");
		i = 0;
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL; /* Null-terminate the array */
		/* Check for exit command */
		if (i > 0 && strcmp(args[0], "exit") == 0)
		{
			break; /* Exit the shell */
		}
		/* Execute other commands */
			execute_command(args);
	}
	printf("\n"); /* Print a newline before exiting */
	return (EXIT_SUCCESS);
}
