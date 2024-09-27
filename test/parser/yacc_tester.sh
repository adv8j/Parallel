#!/bin/bash

# Set default value for print_output flag
out=false

# Check if --print-output flag is passed as an argument
for arg in "$@"; do
    if [ "$arg" == "--out" ]; then
        out=true
        break
    fi
done

input_folder="test/parser/input"
log_file="test/parser/logs"
> "$log_file"

# ANSI color codes
yellow="\033[1;33m"
green="\033[1;32m"
red="\033[1;31m"
reset="\033[0m"

# Process files in numerical order
for file in $(ls "$input_folder" | grep -E '^[0-9]+(_wrong)?\.txt$' | sort -n); do
    filename=$(basename -- "$file")

    # Check if the file is a number.txt or number_wrong.txt
    if [[ "$filename" =~ ^([0-9]+)(_wrong)?\.txt$ ]]; then
        # Get the number from the filename
        number=${BASH_REMATCH[1]}
        is_wrong=${BASH_REMATCH[2]}

        # Reset the syntax_error flag for each file
        syntax_error=false

        # Run parser.out, pipe its output to grep, and capture result
        if $out; then
            # Print and check for "syntax error"
            output=$(./parser.out < "$input_folder/$filename" 2>&1)
            echo -n "$output"
        else
            # Suppress stdout but still check for "syntax error"
            output=$(./parser.out < "$input_folder/$filename" 2>&1)
        fi

        # Check for the 'syntax error' in output
        if echo "$output" | grep -q "syntax error"; then
            syntax_error=true
        fi

        # Evaluate based on the syntax_error flag and the presence of _wrong in the filename
        if [ "$syntax_error" == true ]; then
            if [ -z "$is_wrong" ]; then
                echo -e "$number.txt: Test Failed (Syntax Error)" >> "$log_file"
                printf "${yellow}%2d.txt:${reset} ${red}Test Failed${reset}\n" "$number"
            else
                echo -e "$number.txt: Test Passed (Syntax Error Handled)" >> "$log_file"
                printf "${yellow}%2d.txt:${reset} ${green}Test Passed${reset}\n" "$number"
            fi
        else
            if [ -z "$is_wrong" ]; then
                echo -e "$number.txt: Test Passed" >> "$log_file"
                printf "${yellow}%2d.txt:${reset} ${green}Test Passed${reset}\n" "$number"
            else
                echo -e "$number.txt: Test Failed" >> "$log_file"
                printf "${yellow}%2d.txt:${reset} ${red}Test Failed${reset}\n" "$number"
            fi
        fi
    fi
done
