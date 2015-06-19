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
    int marked[numVertices];
    int* heap;

    newMatrix = initializeMatrix();
    heap = initializeHeap();
    type = 1;

    for(i = 0; i < numVertices; i++)
    {
        cost[i] = INT_MAX;
        previous[i] = -1;
    }
    cost[0] = 0;

    for(i = 1; i <= numVertices; i++)
    {
        heap[i] = cost[i-1];
    }

    buildHeap(heap, numVertices);

    while(!isEmpty(heap))
    {
        vertex = heapExtract(heap); //extrai o minimo custo

        for(i = 0; i < numVertices; i++)
        {
            if (vertex == cost[i] && marked[i] != 1) {
                vertex = i;
                break;
            }
        }
     
        neighboors = getNeighboors(adjMatrix, vertex);
        for(i = 0; i < neighboorsLen; i++)
        {
            z = neighboors[i];
            if(marked[z] != 1 && cost[z] > adjMatrix[vertex][z])
            {
                cost[z] = adjMatrix[vertex][z];
                if (inHeap(heap, z+1)) {
                    modifyKey(heap, z+1, cost[z]);
                }
                previous[z] = vertex;
            }
        }
        marked[vertex] = 1;
    }

    printf("\nVector Previous -> [ ");
    for(i = 0; i < numVertices; i++)
    {
        printf("%d ", previous[i]);
    }
    printf("]");

    printf("\nVector Cost ->     [ ");
    for(i = 0; i < numVertices; i++)
    {
        printf("%d ", cost[i]);
    }
    printf("]\n\n"); 

    for(i = 1; i < numVertices; i++)
    {
        newMatrix[i][previous[i]] = newMatrix[previous[i]][i] = cost[i];
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
