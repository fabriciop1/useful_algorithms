all: tree.exe

tree.exe: BSTree.o BSTreeMain.o
	gcc BSTree.o BSTreeMain.o -o tree.exe

BSTreeMain.o: BSTreeMain.c
	gcc -c BSTreeMain.c -o BSTreeMain.o

BSTree.o: BSTree.c header.h
	gcc -c BSTree.c -o BSTree.o


clean:
	-rm -f *.o
	-rm -f tree.exe
