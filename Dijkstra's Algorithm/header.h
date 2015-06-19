#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*
    Algoritmo by Fabricio Paes
    UFRPE - UAG
    Bacharelado em Ciencia da Computa��o 2015.1
    Algoritmos e Estruturas de Dados II - Rian Gabriel
*/
int numVertices, adjEdges; // numVertices do grafo e numero de arestas de um determinado vertice

void Dijkstra(int**, int); // Algoritmo de Djikstra
int** initializeMatrix(); // Inicializa uma matriz din�mica com todas as posi��es iniciadas em 0.
void printMatrix(int**); // M�todo que imprime qualquer matrix
int* getNeighboors(int**, int); //m�todo para localizar os vizinhos de v, ou no caso, quantas arestas existem partindo de v e quais s�o elas.
void printVectors(int*, int*); // imprime os vetores dist e prev

#endif // HEADER_H_INCLUDED
