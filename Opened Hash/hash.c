#include "header.h"
#include<stdio.h>
#include<stdlib.h>

void initialize(int table[])
{
    int i;
    for (i = 0; i < m; i++)
    {
        table[i] = -32767;
    }
}

void print(int* table)
{
    int i;
    for(i = 0; i < m; i++)
    {
	if(table[i] == -32767)
	{
		printf("Empty \n");
		continue;
	}
        printf("%d \n", table[i]);
    }
}

void insert(int table[], int k)
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (table[get_function(k, i)] == -32767) {
            table[get_function(k , i)] = k;
            break;
        }
    }
}

int search(int table[], int k)
{
    int i = 0;
    while (i < m)
    {
        if (table[get_function(k, i)] == k)
            return get_function(k, i);
        else if (table[get_function(k, i)] == -32767);
            return -32767;
        i++;
    }
    return -32767;
}

void removePos(int table[], int k)
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (k == get_function(k, i))
        {
            table[get_function(k, i)] = -32767;
        }
    }
}

int get_function(int k, int i)
{
    int base = get_function_base(k);
    int hashFunction = (base + i) % m;
    return hashFunction;
}

int get_function_base(int k)
{
    int baseFunction = k % m; // Pelo método da divisão
    return baseFunction;
}
