#include "main.h"

/**
 * main - this is the main function\
 * to recieve argument from the user for processing
 * 
 * Return: return EXIT_SUCCESS
*/

int main(void) {
    run_script();
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];
    size_t i;

    while (1) {
        /* Print shell prompt */
        printf("($) ");
        fflush(stdout);

        /* Read user input */
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF
        }
        /* Remove newline character */
        input[strcspn(input, "\n")] = '\0';
        /* Tokenize the input into arguments */
        char *token = strtok(input, " ");
        i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; /* Null-terminate the array */
        /* Check for exit command */
        if (i > 0 && strcmp(args[0], "exit") == 0) {
            break; // Exit the shell
        }
        /* Check for ls command */
        if (i > 0 && strcmp(args[0], "ls") == 0) {
            execute_command(args);
        } else {
            /* Execute other commands */
            execute_command(args);
        }
         // Check if the command is in the list
    }
    printf("\n"); /* Print a newline before exiting */
    return EXIT_SUCCESS;
}

