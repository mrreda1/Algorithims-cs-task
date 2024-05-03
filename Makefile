CC=gcc

build: *.c
	$(CC) *.c -o run
debug: *.c
	$(CC) *.c -g -o debug
