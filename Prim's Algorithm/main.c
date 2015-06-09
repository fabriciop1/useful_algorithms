#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int i, j;
    int** matrix;
    int** adjMatrix;

    numVertices = 6;
    adjMatrix = initializeMatrix();

    for(i = 0; i < numVertices; i++)
    {
        for(j = 0; j < numVertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    matrix = Prim(adjMatrix);

    print(matrix);
    return 0;
}
