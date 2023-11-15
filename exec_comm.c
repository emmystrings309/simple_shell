#include "main.h"

/**
  * is_command_in_lists - check for command in list of comm
  * @command: recieves the command from the user
  *
  * Return: return 1 if found, else 0
  */

int is_command_in_lists(const char *command)
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
		/* Compare the entered command with the line from the file */
		if (strcmp(command, line) == 0)
		{
			fclose(file);
			return (1); /* Command found in the list */
		}
	}
	fclose(file);
	return (0); /* Command not found in the list */
}

/**
  * execute_command - this executes the command given to it
  * @args: the argument passed in is recieved
  *
  * Return: it returns void
  */

void execute_command(char *args[])
{
	char full_path[1024];

	/* Check if the command is in the list */
	if (is_command_in_lists(args[0]))
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{/* Child process */


			if (execve(args[0], args, NULL) == -1)
			{
				/* If execve fails, try using full path if available */
				snprintf(full_path, sizeof(full_path), "/bin/%s", args[0]);

				if (execve(full_path, args, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}				}
			}
			else
			{
				/* Parent process */
				int status;

				waitpid(pid, &status, 0);
			}
		}
		else
		{
			printf("Command not allowed.\n");
		}
}
