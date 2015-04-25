#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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
void preOrder(Node*);
void posOrder(Node*);
void inOrder(Node*);
Node* search(Node*, int);
Node* minimum(Node*);
Node* maximum(Node*);
Node* successor(Node*);
Node* predecessor(Node*);
Node* leftRotation(Node*, Node*);
Node* rightRotation(Node*, Node*);
Node* doubleLeftRotation(Node*, Node*);
Node* doubleRightRotation(Node*, Node*);
Node* balanceTree(Node*, Node*);

#endif // HEADER_H_INCLUDED
