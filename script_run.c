#include "main.h"

int run_script(void) {
    // Assuming your shell script is named "myscript.sh"
    const char *scriptName = "./list_commands.sh";

    // Use the system function to execute the shell script
    int result = system(scriptName);

    if (result == -1) {
        // system command failed
        perror("Error running the shell script");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
