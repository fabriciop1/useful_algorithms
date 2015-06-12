#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* Code by : Fabricio Paes Ferreira
    Algoritmos e Estruturas de Dados II - UFRPE - UAG 2015.1 - Prof. Rian Gabriel
    Algoritmo de Prim usando Heap como Fila de Prioridade
*/

int main()
{
    int i, j, select;
    int** adjMatrix;
    int** newMatrix;

    do {
        printf("\n\n ~PRIM'S ALGORITHM by Fabricio Paes ~ \n ");
        printf("\n(0) - Exit\n(1) - Apply Algorithm\n(2) - Print the MST's Adjacency Matrix\n");
        scanf("%d", &select);
        switch(select)
        {
            case 0:
                break;
            case 1:
                printf("\nType the number of vertices: ");
                scanf("%d", &numVertices);
                adjMatrix = initializeMatrix();
                printf("\nType the graph's adjacency matrix: \n");
                for(i = 0; i < numVertices; i++)
                {
                    for(j = 0; j < numVertices; j++)
                    {
                        scanf("%d", &adjMatrix[i][j]);
                    }
                }
                newMatrix = Prim(adjMatrix); // retorna os vetores cost e previous em um único vetor

                break;
            case 2:
                printf("Minimum Spanning Tree: \n\n");
                print(newMatrix);
                break;
            default:
                printf("ERROR. Option is not valid. Try again.");
                break;
        }
    } while (select != 0);

    free(adjMatrix);
    free(newMatrix);

    return 0;
}
