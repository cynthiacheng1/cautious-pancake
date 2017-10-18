all: musiclibrary.c
	gcc -o all musiclibrary.c

clean:
	rm *.o

run: all
	./musiclibrary
