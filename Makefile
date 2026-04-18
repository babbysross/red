CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c2x -O2
vpath %.c src

UNAME_S := $(shell uname -s)
EXE = red
ifneq (,$(findstring MINGW, $(UNAME_S)))
EXE = red.exe
endif

SRCS = main.c syntax.c
OBJS = $(SRCS:%.c=%.o)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXE)
