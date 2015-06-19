all: dijkstra.exe

dijkstra.exe: djikstra.o heap.o main.o
	gcc djikstra.o heap.o main.o -o dijkstra.exe

heap.o: heap.c heap.h
	gcc -c heap.c -o heap.o

main.o: main.c
	gcc -c main.c -o main.o


clean:
	rm -f *.o
	rm -f dijkstra.exe
