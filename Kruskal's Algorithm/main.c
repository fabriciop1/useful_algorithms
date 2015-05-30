#include <stdio.h>
#include <stdlib.h>
#include "header.h"

                                /* FABRICIO PAES FERREIRA */

int main()
{
    int i, j, numEdges, select;
    int** adjacencyMatrix, newMatrix;


    printf("\t\t KRUSKAL's ALGORITHM \t\t\n\n");

    do
    {
        printf("Insert the number of vertices: ");
        scanf("%d", &vertices);

        adjacencyMatrix = initializeMatrix(adjacencyMatrix, vertices);

        printf("Insert the graph's adjacency matrix:\n");
        for (i = 0; i < vertices; i++)
        {
            for(j = 0; j < vertices; j++)
            {
                scanf("%d", &adjacencyMatrix[i][j]);
            }
        }

        //numEdges = getNumEdges(adjacencyMatrix, vertices);
        newMatrix = Kruskal(adjacencyMatrix);

        print(newMatrix);
        printMinimumCost(newMatrix);
        printf("\n\nContinue?(0 - no | 1 - yes) ");
        scanf("%d", &select);
        free(adjacencyMatrix);
        free(newMatrix);

    }while (select != 0);

    return 0;
}
