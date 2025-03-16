CC=gcc
CFLAGS=-g -Wall -Werror

all: passmgr

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

passmgr: main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o passmgr
