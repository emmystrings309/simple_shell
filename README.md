**README.md**

# Emmy~strings

## Simple Shell

This is a comprehensive shell implementation in C that combines basic functionality with advanced features. The shell provides a command-line interface for users to interact with the operating system. It supports executing both basic commands and user-defined scripts.

### How to Use

1. Compile the program:
    ```
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
    ```

2. Run the shell:
    ```
    ./hsh
    ```

3. Once the shell is running, you can enter commands at the prompt, such as:
    ```
    ($) ls -l
    ```

4. To exit the shell, use the 'exit' command:
    ```
    ($) exit
    ```

### Features

- Executes basic shell commands.
- Supports user-defined scripts.
- Provides a simple command-line interface.
- Restricts the use of commands based on a predefined list.

### Files

- `main.c`: Contains the main functionality of the shell.
- `main.h`: Header file for the main program.
- `list_commands.sh`: Shell script to generate a list of executable commands in the current system and store them in `command_list.txt`.
- `command_list.txt`: Text file containing a list of allowed commands.

### How to Update Allowed Commands

1. Modify `list_commands.sh` to customize the generation of the command list.
2. Run `list_commands.sh` to update the `command_list.txt` file:
    ```
    ./list_commands.sh
    ```

### Contributors

- Okikijesu Emmanuel

Feel free to contribute to the project by forking and submitting a pull request.

---
