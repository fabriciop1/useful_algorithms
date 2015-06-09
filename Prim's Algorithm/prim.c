#include<stdlib.h>
#include<stdio.h>
#include "heap.h"
#include "header.h"
#include <limits.h>

int** Prim(int** adjMatrix)
{
    int i, j, z, vertex;
    int* neighboors;
    int** newMatrix;
    int cost[numVertices];
    int previous[numVertices];

    newMatrix = initializeMatrix();

    for(i = 0; i < numVertices; i++)
    {
        cost[i] = INT_MAX;
        previous[i] = -1;
    }
    cost[0] = 0;

    int* heap = initializeHeap();
    type = 1;

    for(i = 1; i <= numVertices; i++)
    {
        heap[i] = i;
    }

    buildHeap(heap, numVertices);

    while(isEmpty(heap) != 1)
    {
        vertex = heapExtract(heap) - 1;
        printf("%d\n", vertex);
        neighboors = getNeighboors(adjMatrix, vertex);
        for(i = 0; i < neighboorsLen; i++)
        {
            z = neighboors[i];
            if(cost[z] > adjMatrix[vertex][z])
            {
                cost[z] = adjMatrix[vertex][z];
                previous[z] = vertex;
            }
        }
    }

    for(i = 0; i < numVertices; i++)
    {
        printf("%d ", previous[i]);
      // newMatrix[i][previous[i]] = newMatrix[previous[i]][i] = cost[i];
    }

    return newMatrix;
}

int* getNeighboors(int** adjMatrix, int v)
{
    int i = 0, j;
    int* neighboors = malloc(numVertices * sizeof(int));
    neighboorsLen = 0;

    for(j = 0; j < numVertices; j++)
    {
        if(adjMatrix[v][j] != 0)
        {
            neighboors[i] = j;
            i++;
            neighboorsLen++;
        }
    }
    return neighboors;
}

int** initializeMatrix()
{
    int** matrix;
    int i, j;
    matrix = (int**)malloc(numVertices * sizeof(int*));
    for(i = 0; i < numVertices; i++)
    {
        matrix[i] = (int*)malloc(numVertices * sizeof(int));
        for(j = 0; j < numVertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void print(int** adjMatrix)
{
    int i, j;
    for(i = 0; i < numVertices; i++)
    {
        for(j = 0; j < numVertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
