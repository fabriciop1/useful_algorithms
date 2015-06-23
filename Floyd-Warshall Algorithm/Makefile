all: floydWarshall.exe

floydWarshall.exe: floydWarshall.o main.o
	gcc floydWarshall.o main.o -o floydWarshall.exe

main.o: main.c
	gcc -c main.c -o main.o


clean:
	-rm -f *.o
	-rm -f floydWarshall.exe
