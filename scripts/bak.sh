#!/bin/bash

# Add .bak ending to files given as arguments
# TODO:
# add -f flag to edit originals in-place
# add -r flag to go recursively into folders

files="$@"

for file in "$files"; do
        if [ -f "$file" ]; then
                cp -uv "$file" "$file".bak
        fi
done
