all: avl.exe

avl.exe: AVLTree.o AVLTreeMain.o
	gcc AVLTree.o AVLTreeMain.o -o avl.exe

AVLTreeMain.o: AVLTreeMain.c
	gcc -c AVLTreeMain.c -o AVLTreeMain.o

AVLTree.o: AVLTree.c header.h
	gcc -c AVLTree.c -o AVLTree.o


clean:
	-rm -f *.o
	-rm -f avl.exe
