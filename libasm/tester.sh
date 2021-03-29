#!bin/sh

make re
gcc main.c libasm.a -I./include
./a.out