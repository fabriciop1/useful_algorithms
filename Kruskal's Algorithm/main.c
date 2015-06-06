#include <stdio.h>
#include <stdlib.h>
#include "header.h"

                                /* FABRICIO PAES FERREIRA */

int main()
{
    int i, j, select;
    int** adjacencyMatrix;
    int** newMatrix;

    printf("\t\t KRUSKAL's ALGORITHM \t\t\n\n");

    do
    {
        printf("\nOPTIONS:\n0 - Exit\n1 - Insert Graph\n2 - Breadth-Search\nType the chosen option: ");
        scanf("%d", &select);

        switch(select)
        {
            case 0:
                break;
            case 1:
                printf("Insert the number of vertices: ");
                scanf("%d", &vertices);

                adjacencyMatrix = initializeMatrix(adjacencyMatrix, vertices);

                printf("\nInsert the graph's adjacency matrix:\n");

                for (i = 0; i < vertices; i++)
                {
                    for(j = 0; j < vertices; j++)
                    {
                        scanf("%d", &adjacencyMatrix[i][j]);
                    }
                }

                newMatrix = Kruskal(adjacencyMatrix);

                print(newMatrix);

                for(i = 0; i < vertices; i++)
                {
                    free(adjacencyMatrix[i]);
                    free(newMatrix[i]);
                }
                free(adjacencyMatrix);
                free(newMatrix);
                break;
            case 2:
                printf("\nVertices ordered by breadth: \n");
                breadthFirstSearch(adjacencyMatrix, 0);
                break;
            default:
                printf("\n\nTry again.\n\n");
        }

    }while (select != 0);

    return 0;
}
