#!/bin/zsh

filename=$1


if [[ -f "$filename" ]]; then 
    # echo "\nCompiling $filename into a.out\n"
    g++ -std=c++20 "$filename" -o a.out

    if [[ $? -ne 0 ]]; then
        echo "\n --- ❌ COMPILATION ERROR ---"
    elif [[ -x a.out ]]; then
        echo "\n --- ✅ COMPILATION SUCCESS  ---\n"
        ./a.out < ~/input.in > ~/output.out
    fi
else
    echo "ERROR! $filename not found"
fi