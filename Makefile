# Algorithmique

CC = gcc
CFLAGS = -c -Wall

all: constructeurMAC

constructeurMAC: main.o
	$(CC) main.o -o ConstructeurMAC -lm

main.o: main.cpp
	$(CC) $(CFLAGS) main.c
clean:
	rm -rf *.o
