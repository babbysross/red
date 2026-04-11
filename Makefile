CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c2x -O2
VPATH = src

kilo: kilo.c
	$(CC) $(CFLAGS) $? -o ./$@
