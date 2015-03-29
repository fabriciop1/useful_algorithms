#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes {
    int* father;
    int* leftSon;
    int* rightSon;
    int key;
} Node;

Node T; //root

bool insert(Node, Node);
bool transplant(Node, Node, Node);
bool remove(Node, Node);
int search(Node, int);
int minimum(Node);
int maximum(Node);
int successor(Node);
int predecessor(Node);


int main()
{
    printf("Hello world!\n");
    return 0;
}
