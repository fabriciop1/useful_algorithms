#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

int numVertices;
int neighboorsLen;

int** Prim(int**);
int* getNeighboors(int**, int);
int** initializeMatrix();
void print(int**);


#endif // HEADER_H_INCLUDED
