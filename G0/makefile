
prog: main.o array.o interface.o
	gcc -o prog main.o array.o interface.o

main.o: main.c array.h interface.h
	gcc -c main.c

api.o: array.c array.h
	gcc -c array.c

interface.o: interface.c interface.h
	gcc -c interface.c