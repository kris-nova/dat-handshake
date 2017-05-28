
pwd:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: clean client server

C_OBJECTS = $(patsubst src/client/%.c, src/client/%.o, $(wildcard src/client/*.c))
C_HEADERS = $(wildcard src/client/*.h)
S_OBJECTS = $(patsubst src/server/%.c, src/server/%.o, $(wildcard src/server/*.c))
S_HEADERS = $(wildcard src/server/*.h)

src/client/%.o: src/client/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

src/server/%.o: src/server/%.c $(S_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(S_OBJECTS) $(C_OBJECTS)

client: $(C_OBJECTS)
	$(CC) $(C_OBJECTS) -Wall $(LIBS) -o $@

server: $(S_OBJECTS)
	$(CC) $(S_OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f src/client/*.o
	-rm -f src/server/*.o
	-rm -f client
	-rm -f server

run:
	./server &
	./client

shell:
	docker run -i -t -v $(pwd):/tcp -w /tcp --rm base/archlinux:latest ./BUILD