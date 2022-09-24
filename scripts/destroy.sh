#!/bin/bash

# Shred an remove

for file in $@; do
        if [ -f "$file" ]; then
                shred "$file" && rm "$file"
        fi
done
