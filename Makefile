CC="gcc"
flags="-g3"

build: ./*/*.c main.c
	$(CC) ./*/*.c main.c -o run
debug: ./*/*.c main.c
	$(CC) ./*/*.c main.c $(flags) -o debug
