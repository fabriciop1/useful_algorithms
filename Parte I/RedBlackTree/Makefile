all: RBTree.exe

RBTree.exe: RBTree.o RBTreeMain.o
	gcc RBTree.o RBTreeMain.o -o RBTree.exe

RBTreeMain.o: RBTreeMain.c
	gcc -c RBTreeMain.c -o RBTreeMain.o


clean:
	-rm -f *.o
	-rm -f RBTree.exe
