#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*
    Algoritmo by Fabricio Paes
    UFRPE - UAG
    Bacharelado em Ciencia da Computação 2015.1
    Algoritmos e Estruturas de Dados II - Rian Gabriel
*/
int numVertices, adjEdges; // numVertices do grafo e numero de arestas de um determinado vertice

void Dijkstra(int**, int); // Algoritmo de Djikstra
int** initializeMatrix(); // Inicializa uma matriz dinâmica com todas as posições iniciadas em 0.
void printMatrix(int**); // Método que imprime qualquer matrix
int* getNeighboors(int**, int); //método para localizar os vizinhos de v, ou no caso, quantas arestas existem partindo de v e quais são elas.
void printVectors(int*, int*); // imprime os vetores dist e prev

#endif // HEADER_H_INCLUDED
