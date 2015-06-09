
all: heap.exe

heap.exe: Heap.o HeapMain.o
	gcc Heap.o HeapMain.o -o heap.exe

HeapMain.o: HeapMain.c
	gcc -c HeapMain.c -o HeapMain.o

Heap.o: Heap.c header.h
	gcc -c Heap.c -o Heap.o


clean:
	-rm -f *.o
	-rm -f heap.exe
