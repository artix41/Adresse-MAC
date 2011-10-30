# MAC_ADDRESS : manufacturer

CC = gcc
CFLAGS = -std=c99 -c -Wall

all: main.o usage.o mac_address_manufacturer.o
	$(CC) $^ -o manufacturer -lm

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
clean:
	rm -rf *.o
update:
	wget -N http://standards.ieee.org/develop/regauth/oui/oui.txt
