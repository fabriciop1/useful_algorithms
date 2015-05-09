HEADER = header.h
OBJECTSDEFAULT = BSTreeMain.o BSTree.o
OBJECTSAVL = AVLTreeMain.o AVLTree.o
OBJECTSRB = RBTreeMain.o RBTree.o
OBJECTSHEAP = HeapMain.o Heap.o
CC = gcc

default: BSTree

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

BSTree: $(OBJECTSDEFAULT)
	$(CC) $(OBJECTSDEFAULT) -o $@

avlTree: $(OBJECTSAVL)
	$(CC) $(OBJECTSAVL) -o $@

RBTree: $(OBJECTSRB)
	$(CC) $(OBJECTSRB) -o $@

Heap: $(OBJECTSHEAP)
	$(CC) $(OBJECTSHEAP) -o $@

clean:
	-rm -f *.o
	-rm -f avlTree BSTree RBTree Heap
