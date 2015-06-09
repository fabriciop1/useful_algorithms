all: kruskal.exe

kruskal.exe: kruskal.o queue.o main.o
	gcc kruskal.o queue.o main.o -o kruskal.exe

main.o: main.c
	gcc -c main.c -o main.o

queue.o: queue.c queue.h
	gcc -c queue.c -o queue.o


clean:
	-rm -f *.o
	-rm -f kruskal.exe
