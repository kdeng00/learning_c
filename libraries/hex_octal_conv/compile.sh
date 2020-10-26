if [ ! -d "bin" ]; then
    mkdir bin
    echo "created bin directory"
fi

if [ ! -d "bin/static" ]; then
    mkdir bin/static
    echo "created bin/static directory"
fi

gcc -c src/hex.c -Iinclude -o bin/static/hex.o

ar rcs bin/static/libhexoctalconv.a bin/static/hex.o
