#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h> 

#define infinity 999

int** FloydWarshall(int** adjMatrix, int vertices)
{
    int k, i, j, min;
    int** P = initializeMatrix(vertices);

    for(i = 0; i < vertices; i++) {
	for(j = 0; j < vertices; j++) {
		if(adjMatrix[i][j] != infinity && i != j)
			P[i][j] = i+1;
	}
    }

    for(k = 0; k < vertices; k++)
    {
        for(i = 0; i < vertices; i++)
        {
            for(j = 0; j < vertices; j++)
            {
                if(adjMatrix[i][k] == infinity || adjMatrix[k][j] == infinity)
                {
                   continue;
                }
		if(adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
                {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    P[i][j] = k+1;
                }
            }
        }
    }
    printf("Previous matrix: \n");
    print(P, vertices);
    printf("\n");	
 	
    return adjMatrix;
}

int** initializeMatrix(int vertices)
{
    int** matrix;
    int i, j;
    matrix = (int**)malloc(vertices * sizeof(int*));
    for(i = 0; i < vertices; i++)
    {
        matrix[i] = (int*)malloc(vertices * sizeof(int));
        for(j = 0; j < vertices; j++)
        {
            matrix[i][j] = -1;
        }
    }
    return matrix;
}

void print(int** adjMatrix, int vertices)
{
    int i, j;
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            printf("%d\t", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
