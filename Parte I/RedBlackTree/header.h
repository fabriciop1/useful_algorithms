#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct Node {
    struct Node *father;
    struct Node *leftSon;
    struct Node *rightSon;
    int key;
    int color; // 0 = black    1 = red
} Node;

Node* insert(Node*, Node*, Node*);
Node* transplant(Node*, Node*, Node*);
Node* removeNode(Node*, Node*, Node*);
void printTree(Node*, Node*);
void preOrder(Node*);
void posOrder(Node*);
void inOrder(Node*);
Node* search(Node*, int, Node*);
Node* minimum(Node*, Node*);
Node* maximum(Node*, Node*);
Node* successor(Node*, Node*);
Node* predecessor(Node*, Node*);
Node* leftRotation(Node*, Node*);
Node* rightRotation(Node*, Node*);
Node* doubleLeftRotation(Node*, Node*);
Node* doubleRightRotation(Node*, Node*);
Node* balanceTree(Node*, Node*);
Node* createDummy(Node*);
Node* createNode(Node*, int);
Node* situation3(Node*, Node*);

#endif // HEADER_H_INCLUDED
