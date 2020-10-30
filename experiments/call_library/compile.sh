#!/bin/sh

gcc -c main.c -I../../libraries/test_library1/include -o bin/main.o

cd ../../libraries/test_library1
./compile.sh

cd ../../experiments/call_library


gcc bin/main.o -L../../libraries/test_library1/bin/static -ltestlibrary -o bin/call_library
