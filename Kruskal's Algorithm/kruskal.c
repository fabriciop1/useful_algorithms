#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "header.h"

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
    int i, j, minimumCost = 0;
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
            if(adjMatrix[i][j] != 0 && i < j)
            {
                minimumCost += adjMatrix[i][j];
            }
        }
        printf("\n");
    }
    printf("\nMinimum Cost: %d \n\n", minimumCost);
}

int findSet(int* sets, int vertex)
{
    return sets[vertex];
}

void setUnion(int* sets, int vertex1, int vertex2)
{
    int vertexValue1 = sets[vertex1];
    int vertexValue2 = sets[vertex2];
    int i;

    for (i = 0; i < vertices; i++)
    {
        if (sets[i] == vertexValue1)
        {
            sets[i] = vertexValue2;
        }
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
            j++; //arestas++
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

void breadthFirstSearch(int** adjMatrix, int root)
{
    int i;
    int* neighboors;
    Node* node;
    int closedVector[vertices];
    Queue* queue;

    queue = initializeQueue();

    QueueAdd(queue, root);

    for(i = 0; i < vertices; i++)
    {
        closedVector[i] = 0;
    }

    closedVector[root] = 1;
    while(QueueIsEmpty(queue) == 0)
    {
        node = QueuePop(queue);
        neighboors = getNeighboors(adjMatrix, node->key);
        for(i = 0; i < length; i++)
        {
            if (closedVector[neighboors[i]] == 0)
            {
                QueueAdd(queue, neighboors[i]);
                closedVector[neighboors[i]] = 1;
            }
        }
        printf("%d ", node->key);
        free(node);
    }
    printf("\n\n");
    excludeQueue(queue);
}

int* getNeighboors(int** adjMatrix, int v)
{
    int i = 0, j;
    int* neighboors = malloc(vertices * sizeof(int));

    length = 0;

    for(j = 0; j < vertices; j++)
    {
        if(adjMatrix[v][j] != 0)
        {
            neighboors[i] = j;
            i++;
            length++;
        }
    }
    return neighboors;
}
