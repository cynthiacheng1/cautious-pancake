run: all
	./run

all: songs.o main.o
	gcc -o run songs.o main.o

songs.o: musiclibrary.c
	gcc -c musiclibrary.c

main.o: main.c headers.h
	gcc -c main.c

clean:
	rm -f *.o
	rm -f *~
	rm run
