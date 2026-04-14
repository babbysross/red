CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c2x -O2
VPATH = src

UNAME_S := $(shell uname -s)
EXE = red
ifneq (,$(findstring MINGW, $(UNAME_S)))
EXE = red.exe
endif

$(EXE): red.c
	$(CC) $(CFLAGS) $? -o $@
