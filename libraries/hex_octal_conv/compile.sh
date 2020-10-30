#!/bin/bash

if [ -n "$1" ]; then
    compile_type=$1
else
    compile_type="debug"
fi


if [ ! -d "bin" ]; then
    mkdir bin
    echo "created bin directory"
fi

if [ ! -d "bin/static" ]; then
    mkdir bin/static
    echo "created bin/static directory"
fi

if [ "$compile_type" = "debug" ]; then
    echo "Compiling for debug version"
    gcc -c src/hex.c -Iinclude -o bin/static/hex.o -O0
elif [ "$compile_type" = "release" ]; then
    echo "Compiling for release version"
    gcc -c src/hex.c -Iinclude -o bin/static/hex.o -O3
else
    echo "Compiling for debug by default"
    gcc -c src/hex.c -Iinclude -o bin/static/hex.o -O0
fi

ar rcs bin/static/libhexoctalconv.a bin/static/hex.o
