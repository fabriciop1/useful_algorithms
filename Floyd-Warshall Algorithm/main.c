#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int vertices, i, j;
    scanf("%d", &vertices);
    int** adjMatrix = initializeMatrix(vertices);
    int** pi = initializeMatrix(vertices);

    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            scanf("%d", &adjMatrix[i][j]);

    adjMatrix = FloydWarshall(adjMatrix, vertices);
    printf("Distance Matrix: \n");
    print(adjMatrix, vertices);
}
