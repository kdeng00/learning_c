#!/bin/bash

if [ ! -d "bin" ]; then
    mkdir bin
    echo "Created bin directory"
fi

current_dir=`pwd`
hex_octal_conv_lib_root_dir="../../libraries/hex_octal_conv"
hex_octal_conv_lib_include_dir="$hex_octal_conv_lib_root_dir/include"
hex_octal_conv_lib_dir="$hex_octal_conv_lib_root_dir/bin/static"

gcc -c main.c -I"$hex_octal_conv_lib_include_dir" -o bin/main.o -O3

cd $hex_octal_conv_lib_root_dir
./compile.sh "release"
cd $current_dir

gcc bin/main.o -L"$hex_octal_conv_lib_dir" -lhexoctalconv -o bin/a.out -O3
