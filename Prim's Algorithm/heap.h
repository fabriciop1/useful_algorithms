#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#define heapLength 50 // initial size of the array

int* heap; // the heap structure (array)
int heapSize, type; // heapSize = size of the heap // type = type of the heap -> 0 = max heap        1 = min heap

int inHeap(int*, int); //verify if the position is in the Heap or if it was removed
int isEmpty(int*); // verify if the Heap is empty or not.
int* initializeHeap(); // allocate space in the memory for the heap
int father(int); // returns the position of the father of a node
int leftSon(int); // returns the position of the left son of a node
int rightSon(int); // returns the position of the right of a node
int heapExtract(int*); // extract the root (the most(Max Heap) or the least(Min Heap) value of the heap)
void heapify(int*, int); // keeps the heap properties
void buildHeap(int*,int); // heapifies a given vector with size n
void increaseKey(int*, int, int); // determines where the new value to insert will be stored
void heapInsert(int*, int); // inserts one value on the heap
void printHeap(int*); // prints all the heap structure
void deleteHeap(int*); // free the heap vector
void exchange(int*, int, int); // exchanges 1 vector position with another one

#endif // HEAP_H_INCLUDED
