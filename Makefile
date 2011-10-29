# Adresses MAC : constructeur

CC = gcc
CFLAGS = -std=c99 -c -Wall

all: constructeurMAC

constructeurMAC: main.o
	$(CC) main.o -o ConstructeurMAC -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c
clean:
	rm -rf *.o
