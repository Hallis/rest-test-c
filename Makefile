CC=gcc
CFLAGS=-I .

restmake: main.c
	gcc -o main main.c -I.