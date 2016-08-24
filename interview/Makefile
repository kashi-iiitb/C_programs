CC=gcc
CFLAGS=-I.
DEPS=sort_string.h
OBJ= sort_string.o sort_string_fns.o
%.o: %.c $(DEPS)
	$(CC) -c $@ $< $(CFLAGS)
sort_string:	$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

