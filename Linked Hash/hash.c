#include<stdio.h>
#include<stdlib.h>
#include "hash.h"
#include "list.h"
#include<math.h>

int get_hash_function(int k)
{
    int hashFunction =  m * (fmod(k * A, 1)); // Pelo método da multiplicação
    return hashFunction;
}

void initializeTable(List* table[])
{
    int i;
    for (i = 0; i < m; i++)
    {
        table[i] = initialize();
    }
}
void hash_insert(List* table[], int k)
{
    insert(table[get_hash_function(k)], k);
}

void hash_delete(List* table[], int k)
{
    removeNode(table[get_hash_function(k)], k);
}

Node* hash_search(List* table[], int k)
{
    Node* node = search(table[get_hash_function(k)], k);
    return node;
}

void hash_print(List* table[])
{
    int i;
    for(i = 0; i < m; i++)
    {
        printf("\nPosicao %d: ", i);
        print(table[i]);
        printf("\n");
    }
}

void hash_free_all(List* table[])
{
    int i;
    for(i = 0; i < m; i++)
    {
        exclude(table[i]);
    }
}
