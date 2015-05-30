HEADER = header.h hash.h
OBJECTSDEFAULT = BSTreeMain.o BSTree.o
OBJECTSAVL = AVLTreeMain.o AVLTree.o
OBJECTSRB = RBTreeMain.o RBTree.o
OBJECTSHEAP = HeapMain.o Heap.o
OBJECTSLINKEDHASH = main.o linkedList.o hash.o
OBJECTSHASH = main.o hash.o
OBJKRUSKAL = main.o kruskal.o
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

LinkedHash: $(OBJECTSLINKEDHASH)
	$(CC) $(OBJECTSLINKEDHASH) -o $@  -lm

OpenedHash: $(OBJECTSHASH)
	$(CC) $(OBJECTSHASH) -o $@

Kruskal: $(OBJKRUSKAL)
	$(CC) $(OBJKRUSKAL) -o $@


clean:
	-rm -f *.o
	-rm -f avlTree BSTree RBTree Heap LinkedHash OpenedHash Kruskal
