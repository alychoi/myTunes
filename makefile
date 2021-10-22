all: main.o musiclist.o musiclibrary.o
	gcc -o project00 main.o musiclist.o musiclibrary.o

main.o: main.c musiclist.h musiclibrary.h
	gcc -c main.c

musiclist.o: musiclist.c musiclist.h
	gcc -c musiclist.c

musiclibrary.o: musiclibray.c musiclibrary.h
	gcc -c musiclibrary.c

run:
	./project00

clean:
	rm *.o
	rm project00
