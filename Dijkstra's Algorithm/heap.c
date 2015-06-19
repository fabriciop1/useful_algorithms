#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

int father(int position)
{
    return (position / 2);
}

int leftSon(int position)
{
    return (2 * position);
}

int rightSon(int position)
{
    return (2 * position + 1);
}

void deleteHeap(int* vector)
{
    free(vector);
    heapSize = 0;
}

int* initializeHeap()
{
    int* vector;
    vector = malloc(heapLength * sizeof(int));
    if (vector == NULL)
        return NULL;
    heapSize = 0;
    return vector;
}

void buildHeap(int* vector, int size)
{
    int i;
    heapSize = size;
    for(i = heapSize/2; i >= 1; i--)
    {
       heapify(vector, i);
    }
}

int heapExtract(int* vector)
{
    int out;
    if (heapSize < 1) {
        printf("\nError: Heap Underflow.\n");
        return -999;
    }
    out = vector[1];
    vector[1] = vector[heapSize];
    heapSize--;
    heapify(vector, 1);
    return out;
}

int inHeap(int* vector, int position)
{
    if (position <= heapSize)
        return 1;
    return 0;
}

int isEmpty(int* heap)
{
    if (heapSize == 0)
    {
        return 1;
    }
    return 0;
}

void heapify(int* vector, int position)
{
    int greatest, least;
    int left = leftSon(position);
    int right = rightSon(position);
    if(type == 0) {
        if(left <= heapSize && vector[left] > vector[position])
            greatest = left;
        else
            greatest = position;
        if(right <= heapSize && vector[right] > vector[greatest])
            greatest = right;
        if (greatest != position)
        {
            exchange(vector, position, greatest);
            heapify(vector, greatest);
        }
    } else if(type == 1) {
        if(left <= heapSize && vector[left] < vector[position])
            least = left;
        else
            least = position;
        if(right <= heapSize && vector[right] < vector[least])
            least = right;
        if (least != position)
        {
            exchange(vector, position, least);
            heapify(vector, least);
        }
    }
}

void modifyKey(int* vector, int position, int key)
{
    if (type == 0) {
            if(vector[position] > key) {
                printf("\nERROR. The new key is less than the current one.\n");
                return;
            }
        vector[position] = key;
        while(position > 1 && vector[father(position)] < vector[position])
        {
            exchange(vector, position, father(position));
            position = father(position);
        }
    } else if (type == 1) {
        if(vector[position] < key) {
            printf("\nERROR. The new key is more than the current one.\n");
            return;
        }
        vector[position] = key;
        while(position > 1 && vector[father(position)] > vector[position])
        {
            exchange(vector, position, father(position));
            position = father(position);
        }
    }
}

void exchange(int* vector, int position1, int position2)
{
    int aux;
    aux = vector[position1];
    vector[position1] = vector[position2];
    vector[position2] = aux;
}

void heapInsert(int* vector, int key)
{
    heapSize++;
    vector[heapSize] = -32767; // minimum length for an integer
    modifyKey(vector, heapSize, key);
}

void printHeap(int* vector)
{
    int i;
    printf("\n\t## HEAP PRINTED ##\n");
    printf("Vector \t\t LeftSon \t RightSon\n");
    for(i = 1; i <= heapSize; i++) {
            if(leftSon(i) > heapSize && rightSon(i) > heapSize)
                printf("  %d \t\t      \t\t      \n", vector[i]);
            else if(leftSon(i) <= heapSize && rightSon(i) > heapSize)
                printf("  %d \t\t   %d \t\t      \n", vector[i], vector[leftSon(i)]);
            else if(leftSon(i) <= heapSize && rightSon(i) <= heapSize)
                printf("  %d \t\t   %d \t\t    %d\n", vector[i], vector[leftSon(i)], vector[rightSon(i)]);
    }
    printf("\n");
}
