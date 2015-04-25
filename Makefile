HEADER = header.h
OBJECTSDEFAULT = BSTreeMain.o BSTree.o
OBJECTSAVL = AVLTreeMain.o AVLTree.o
OBJECTSRB = RBTreeMain.o RBTree.o
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


clean:
	-rm -f $(OBJECTSDEFAULT) $(OBJECTSAVL) $(OBJECTSRB)

	-rm -f avlTree BSTree RBTree
