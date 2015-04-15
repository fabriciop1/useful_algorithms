HEADER = AVLTree.h
OBJECTS = AVLTreeMain.o AVLTree.o
CC = gcc

default: avlTree

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

avlTree: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f avlTree
