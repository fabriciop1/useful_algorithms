#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
    Algoritmo by Fabricio Paes
    UFRPE - UAG
    Bacharelado em Ciencia da Computação 2015.1
    Algoritmos e Estruturas de Dados II - Rian Gabriel
*/

int main()
{
    int i, j, iniVertex;
    scanf("%d", &numVertices);
    scanf("%d", &iniVertex);

    int** adjMatrix = initializeMatrix();

    for(i = 0; i < numVertices; i++)
    {
        for(j = 0; j < numVertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    Dijkstra(adjMatrix, iniVertex);
    free(adjMatrix);
    return 0;
}
