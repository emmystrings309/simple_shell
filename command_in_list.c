#include "main.h"

/**
 * is_command_in_list - check if command entered
 * is in the list of available command
 * @command: this is the command entered by  the user
 *
 * Return: return zero if the command not found and 1 if found
 */

int is_command_in_list(const char *command)
{
	char line[MAX_INPUT_SIZE];

	FILE *file = fopen("command_list.txt", "r");

	if (file == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		/* Remove newline character */
		line[strcspn(line, "\n")] = '\0';
		/*Compare the entered command with the line from the file */
		if (strcmp(command, line) == 0)
		{
			fclose(file);
			return (1); /* Command found in the list */
		}
	}
	fclose(file);
	return (0); /* Command not found in the list */
}
