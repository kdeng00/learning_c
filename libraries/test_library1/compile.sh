if [ ! -d "bin" ]; then
    mkdir bin
    echo "created bin directory"
fi

if [ ! -d "bin/static" ]; then
    mkdir bin/static
    echo "created bin/static directory"
fi

gcc -c src/test.c -Iinclude -o -std=gnu99 bin/static/test.o

# For shared libraries.
# gcc -fPIC src/test.c -Iinclude -o bin/shared/test.o

ar rcs bin/static/libtestlibrary.a bin/static/test.o

