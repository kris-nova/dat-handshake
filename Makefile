
pwd:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

LIBS = -lm
CC = gcc
CFLAGS =  -ICg -Wno-unused-variable

.PHONY: default all clean

default: clean libnetrep client server

C_OBJECTS = $(patsubst src/client/%.c, src/client/%.o, $(wildcard src/client/*.c))
C_HEADERS = $(wildcard src/client/*.h)
S_OBJECTS = $(patsubst src/server/%.c, src/server/%.o, $(wildcard src/server/*.c))
S_HEADERS = $(wildcard src/server/*.h)
L_OBJECTS = $(patsubst src/libnetrep/%.c, src/libnetrep/%.o, $(wildcard src/libnetrep/*.c))
L_HEADERS = $(wildcard src/libnetrep/*.h)

src/client/%.o: src/client/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

src/server/%.o: src/server/%.c $(S_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

src/libnetrep/%.o: src/libnetrep/%.c $(L_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(S_OBJECTS) $(C_OBJECTS) $(L_OBJECTS)

libnetrep: $(L_OBJECTS)

client: $(C_OBJECTS)
	$(CC) $(C_OBJECTS) -Wall $(LIBS) -o $@ $(L_OBJECTS)

server: $(S_OBJECTS)
	$(CC) $(S_OBJECTS)  -Wall $(LIBS) -o $@

clean:
	-rm -f src/client/*.o
	-rm -f src/server/*.o
	-rm -f src/libnetrep/*.o
	-rm -f client
	-rm -f server

run:
	./server &
	./client

shell:
	docker run -i -t -v $(pwd):/tcp -w /tcp --rm base/archlinux:latest ./BUILD

include:
	ln -s /usr/include .