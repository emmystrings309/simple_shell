# #!/bin/bash

# IFS=:
# for directory in $PATH; do
#     # List all files in the directory
#     for file in "$directory"/*; do
#         # Check if the file is executable
#         if [ -x "$file" ]; then
#             echo "$(basename "$file")"
#         fi
#     done
# done

#!/bin/bash

# IFS=:
# for directory in $PATH; do
#     # List all files in the directory
#     for file in "$directory"/*; do
#         # Check if the file is executable
#         if [ -x "$file" ]; then
#             echo "$(basename "$file")"
#         fi
#     done
# done > command_list.txt


IFS=:
for directory in $PATH; do
    # List all files in the directory
    for file in "$directory"/*; do
        # Check if the file is executable
        if [ -x "$file" ]; then
            command_name=$(basename "$file")
            
            # Check if the command is already in the file
            if ! grep -q "^$command_name$" command_list.txt; then
                echo "$command_name" >> command_list.txt
            fi
        fi
    done
done
