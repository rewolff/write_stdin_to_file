
CC=gcc
CFLAGS=-Wall -O2

PROGS=write_stdin_to_file
all: $(PROGS)

install: $(PROGS)
	cp $(PROGS) /usr/bin

