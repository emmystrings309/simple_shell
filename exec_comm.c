#include "main.h"

// void execute_command(char *args[])
// {
//         pid_t pid = fork();

//         if (pid == -1)
//         {
//                 perror("fork");
//                 exit(EXIT_FAILURE);
//         }
//         else if (pid == 0)
//         {
//                 /* Child process */
//                 if (execve(args[0], args, NULL) == -1)
//                 {
//                         perror("execve");
//                         exit(EXIT_FAILURE);
//                 }
//         }
//         else
//         {
//                 /* Parent process */
//                 int status;
//                 waitpid(pid, &status, 0);
//         }
// }

int is_command_in_lists(const char *command) {
    FILE *file = fopen("command_list.txt", "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[MAX_INPUT_SIZE];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Compare the entered command with the line from the file
        if (strcmp(command, line) == 0) {
            fclose(file);
            return 1; // Command found in the list
        }
    }

    fclose(file);
    return 0; // Command not found in the list
}
void execute_command(char *args[]) {
    // Check if the command is in the list
    if (is_command_in_lists(args[0])) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process

            // Set the TERM environment variable
            putenv("TERM=xterm-256color"); // Set a default terminal type, adjust as needed

            if (execve(args[0], args, NULL) == -1) {
                // If execve fails, try using full path if available
                char full_path[1024];
                snprintf(full_path, sizeof(full_path), "/bin/%s", args[0]);
                if (execve(full_path, args, NULL) == -1) {
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
            }
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    } else {
        printf("Command not allowed.\n");
    }
}
