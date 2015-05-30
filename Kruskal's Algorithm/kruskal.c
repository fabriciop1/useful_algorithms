#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include<limits.h>

                                                    /* FABRICIO PAES FERREIRA */

Edge* arrange(int** adjMatrix, int n)
{
    int i, j, minPos1, minPos2, k = 0;
    int minimum = INT_MAX; // para verificar os menores custos da matriz
    Edge* edges; // array de arestas que sera ordenado

    edges = malloc(n * sizeof(Edge));

    while (k != n) { // repetir para todas as arestas do grafo
        for(i = 0; i < vertices; i++)
        {
            for(j = 0; j < vertices; j++)
            {
                if (adjMatrix[i][j] < minimum && adjMatrix[i][j] != 0) // se o custo da aresta for 0 (nao tem aresta) ou se o custo for menor que o minimo, faça
                {
                    minimum = adjMatrix[i][j];
                    minPos1 = i;
                    minPos2 = j;
                }
            }
        }
        adjMatrix[minPos1][minPos2] = adjMatrix[minPos2][minPos1] = INT_MAX; // As arestas (0,1) e (1,0) são as mesmas, portanto, contamos apenas 1 vez, e retiramos as 2 para encontrar o proximo menor valor
        edges[k].u = minPos1; // guarda-se o vertice u da matriz onde o menor custo foi encontrado
        edges[k].v = minPos2; // guarda-se o vertice v da matriz onde menor custo foi encontrado
        edges[k].cost = minimum; // guarda-se o menor custo encontrado
        minimum = INT_MAX; // minimum = infinito , que servira para encontrar o proximo menor custo

        k++;
    }
    return edges;
}


void makeSet(int* sets, int vertex)
{
    sets[vertex] = vertex;
}

void print(int** adjMatrix)
{
    printf("\n# Minimum Adjacency Matrix for the graph: # \n");
    int i, j;
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int findSet(int* sets, int vertex)
{
    return sets[vertex];
}

void setUnion(int* sets, int vertice1, int vertice2)
{
    int i;
    if (sets[vertice1] < sets[vertice2])
    {
        sets[vertice2] = sets[vertice1];
    } else {
        sets[vertice1] = sets[vertice2];
    }
}

int** Kruskal(int** adjMatrix)
{
    Edge* edges;
    int* sets;
    int** newMatrix;
    int i, j, numEdges;

    sets = malloc(vertices * sizeof(int));

    newMatrix = initializeMatrix(newMatrix, vertices);

    numEdges = getNumEdges(adjMatrix, vertices); // numero de arestas da matriz

    for(i = 0; i < vertices; i++)
    {
        makeSet(sets, i); //cria um componente conexo para cada vertice da matriz
    }

    edges = arrange(adjMatrix, numEdges); // ordena as arestas de acordo com o custo

    for(i = j = 0; j < vertices - 1; i++) // Enquanto newMatrix nao tiver vertices - 1 arestas, faça:
    {
        if(findSet(sets, edges[i].u) != findSet(sets, edges[i].v)) // se componente conexo de u for diferente de componente conexo de v, faça:
        {
            newMatrix[edges[i].u][edges[i].v] = newMatrix[edges[i].v][edges[i].u] = edges[i].cost; // T = T U (e)
            setUnion(sets, edges[i].u, edges[i].v); // uniao dos componentes conexos de u e v
            j++;
        }
    }
    return newMatrix;
}

int** initializeMatrix(int** matrix, int n)
{
    int i, j;
    matrix = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for(j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

int getNumEdges(int** matrix, int length)
{
    int i, j, edges = 0;
    for(i = 0; i < length; i++)
    {
        for(j = 0; j < length; j++)
        {
            if (matrix[i][j] != 0 && i < j)
            {
                edges++;
            }
        }
    }
    return edges;
}

void printMinimumCost(int** matrix)
{
    int cost = 0, i, j;
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            if (matrix[i][j] != 0 && i < j)
            {
                cost += matrix[i][j];
            }
        }
    }
    printf("\nMinimum Cost: %d\n", cost);
}
