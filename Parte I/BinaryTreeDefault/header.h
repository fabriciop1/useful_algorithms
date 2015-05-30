#ifndef BSTREEHEADER_H_INCLUDED
#define BSTREEHEADER_H_INCLUDED

typedef struct Node {
    struct Node *father;
    struct Node *leftSon;
    struct Node *rightSon;
    int key;
} Node;

Node* insert(Node*, Node*);
Node* transplant(Node*, Node*, Node*);
Node* removeNode(Node*, Node*);
void printTree(Node*);
Node* search(Node*, int);
Node* minimum(Node*);
Node* maximum(Node*);
Node* successor(Node*);
Node* predecessor(Node*);


#endif // BSTREEHEADER_H_INCLUDED
