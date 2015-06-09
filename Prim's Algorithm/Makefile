all: prim.exe

prim.exe: prim.o heap.o main.o
	gcc prim.o heap.o main.o -o prim.exe

main.o: main.c
	gcc -c main.c -o main.o

heap.o: Heap.c heap.h
	gcc -c Heap.c -o heap.o


clean:
	-rm -f *.o
	-rm -f prim.exe
