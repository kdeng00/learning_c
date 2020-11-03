#!/bin/bash

if [ ! -d "bin" ]; then
    mkdir bin
    echo "Created bin directory"
fi

gcc -c main.c -std=gnu99 -o bin/main.o -O3

gcc bin/main.o -std=gnu99 -o bin/a.out -O3
