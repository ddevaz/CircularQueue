#!/bin/sh
pwd
gcc -c cq.c
gcc -c ./test.c
gcc cq.o test.o
rm -rf *.o
