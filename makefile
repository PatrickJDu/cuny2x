organizer: main.o createDirectory.o
	gcc -g main.o createDirectory.o -o organizer
main.o: createDirectory.h
	gcc -c main.c
createDirectory.o: createDirectory.h
	gcc -c createDirectory.c
clean:
	rm -f *.o organizer core
