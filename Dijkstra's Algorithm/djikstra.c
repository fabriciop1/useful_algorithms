#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"
#include "heap.h"

/*
    Algoritmo by Fabricio Paes
    UFRPE - UAG
    Bacharelado em Ciencia da Computação 2015.1
    Algoritmos e Estruturas de Dados II - Rian Gabriel
*/

void Dijkstra(int** adjMatrix, int iniVertex)
{
    int i, u, v;
    int dist[numVertices];
    int prev[numVertices];
    int marked[numVertices]; // Para que o algoritmo não modifique a heap e os vetores caso o algoritmo já tenh executado um determinado vértice
    int* heap;
    int* neighboors; // vizinhos

    heap = initializeHeap(); // inicializar heap
    type = 1; // heap de tipo mínimo

    for(i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX; // infinito
        prev[i] = -1;
    }

    dist[iniVertex] = 0;

    for(i = 1; i <= numVertices; i++) { // heap recebe os valores do vetor dist
        heap[i] = dist[i - 1];
    }

    buildHeap(heap, numVertices); // construir heap de mínimo

while(!isEmpty(heap)) // enquanto a heap não estiver vazia
    {
        u = heapExtract(heap); // u recebe o mínimo valor da heap, que é extraído da mesma

        for(i = 0; i < numVertices; i++) { // procura-se o vértice pertencente àquele valor extraído da heap
            if(u == dist[i]) {
                u = i;
                break;
            }
        }

        neighboors = getNeighboors(adjMatrix, u); // vizinhos de u

        for(i = 0; i < adjEdges; i++) { // para todas as arestas (u,v) do grafo (numero de vizinhos)
            v = neighboors[i]; // vizinho i de u
            if(marked[v] != 1 && dist[v] > dist[u] + adjMatrix[u][v]) { // adjMatrix[u][v] = w(u,v)
                dist[v] = dist[u] + adjMatrix[u][v];
                prev[v] = u;
                modifyKey(heap, v+1, dist[v]); // diminui prioridade
            }
        }
        marked[u] = 1;
    }
    printVectors(dist, prev);
}

void printVectors(int* distance, int* previous)
{
    int i;
    printf("\nVector Previous -> [ ");
    for(i = 0; i < numVertices; i++)
    {
        printf("%d ", previous[i]);
    }
    printf("]");

    printf("\nVector Cost ->     [ ");
    for(i = 0; i < numVertices; i++)
    {
        printf("%d ", distance[i]);
    }
    printf("]\n\n");
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

void printMatrix(int** adjMatrix)
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

int* getNeighboors(int** adjMatrix, int v)
{
    int i = 0, j;
    int* neighboors = malloc(numVertices * sizeof(int));
    adjEdges = 0;

    for(j = 0; j < numVertices; j++)
    {
        if(adjMatrix[v][j] != 0)
        {
            neighboors[i] = j;
            i++;
            adjEdges++;
        }
    }
    return neighboors;
}
