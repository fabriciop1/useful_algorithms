#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*                                                  Código feito por: FABRICIO PAES FERREIRA
        Universidade Federal Rural de Pernambuco - UAG
        Algoritmos e Estruturas de Dados II - Professor Rian Gabriel
        Contato: fabriciopaes1@gmail.com
*/

typedef struct
{
    int u; // vertice1
    int v; // vertice2
    int cost; // custo
} Edge; // aresta

int vertices; //numero de vertices

void getMinimumCost(int**); // retorna o custo minimo do grafo.
int getNumEdges(int**, int); // calcula quantas arestas tem em um grafo (em sua matriz adjacente)
int** initializeMatrix(int**, int); // incializar matrix dinamica
void makeSet(int*, int); //Cria os componentes conexos
Edge* arrange(int**, int); // Ordena arestas
int findSet(int*, int); // Verifica o componente conexo de um vertice
void print(int**); // imprime a matriz de adjacencia com o custo minimo do grafo
void setUnion(int*, int, int); // uniao dos componentes conexos de u e v
int** Kruskal(int**); // Algoritmo de Kruskal

#endif // HEADER_H_INCLUDED
