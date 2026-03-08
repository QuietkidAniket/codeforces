#!/bin/bash

# Configuration
SOURCE="server_received.cpp"
EXE="./server_exec"
OUTPUT="output.out"

# Clean up previous runs
rm -f "$EXE"
> "$OUTPUT" # Create/Clear output file

# 1. Compile
# We capture standard error (2>) to output.out to show compilation errors
g++ "$SOURCE" -o "$EXE" 2>> "$OUTPUT"

# Check compilation status (0 = success)
if [ $? -eq 0 ]; then
    echo "--- COMPILATION SUCCESSFUL ---" >> "$OUTPUT"
    echo "--- RUNTIME OUTPUT ---" >> "$OUTPUT"
    
    # 2. Run the executable
    # We append both stdout and stderr to the output file
    # You can add < input.in here if you need standard input for the CP problem
    "$EXE" >> "$OUTPUT" 2>&1
else
    # If compilation failed, the errors are already in output.out
    echo "" >> "$OUTPUT"
    echo "--- COMPILATION FAILED ---" >> "$OUTPUT"
fi