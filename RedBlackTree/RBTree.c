#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Node* insert(Node* root, Node *newNode, Node* dummy)
{
    Node *node = NULL;
    Node *x = root;
    while (x != dummy)
    {
        node = x;
        if (newNode->key < x->key)
        {
            x = x->leftSon;
        }
        else
        {
            x = x->rightSon;
        }
    }
    newNode->father = node;
    if (node == NULL)
    {
        root = newNode;
    }
    else if(newNode->key < node->key)
    {
        node->leftSon = newNode;
    }
    else
    {
        node->rightSon = newNode;
    }

    Node* w = newNode;
    root = balanceTree(root, w);
    return root;
}

Node* situation3(Node* root, Node* sucessor)
{
    Node* brother;
    if (sucessor == sucessor->father->leftSon)
    {
        brother = sucessor->father->rightSon;
    } else {
        brother = sucessor->father->leftSon;
    }
    if (sucessor->color == 0 && brother->color == 1 && sucessor->father->color == 0) // caso 1
    {
        brother->color = 0;
        sucessor->father->color = 1;
        root = leftRotation(root, brother);
        root = situation3(root, sucessor);
    }
    if (sucessor->color == 0 && brother->color == 0 && sucessor->father->color == 0 && brother->leftSon->color == 0 && brother->rightSon->color == 0) //caso 2a
    {
        brother->color = 1;
    }
    if (sucessor->color == 0 && brother->color == 0 && sucessor->father->color == 1 && brother->leftSon->color == 0 && brother->rightSon->color == 0) //caso 2b
    {
        brother->color = 1;
        sucessor->father->color = 0;
    }
    if (sucessor->color == 0 && brother->color == 0 && brother->leftSon->color == 1 && brother->rightSon->color == 0) // caso 3
    {
        brother->color = 1;
        brother->leftSon->color = 0;
        root = rightRotation(root, brother);
        root = situation3(root, sucessor);
    }
    if (sucessor->color == 0 && brother->color == 0 && brother->rightSon->color == 1) // caso 4
    {
        brother->color = sucessor->father->color;
        sucessor->father->color = 0;
        brother->rightSon->color = 0;
        root = leftRotation(root, brother);
    }
    return root;
}

Node* transplant(Node *root, Node *one, Node *two)
{
    if (one->father == NULL)
    {
        root = two;
    } else if(one == one->father->leftSon)
    {
        one->father->leftSon = two;
    } else
    {
        one->father->rightSon = two;
    }
    if(two != NULL)
    {
        two->father = one->father;
    }
    return root;
}

Node* removeNode(Node* root, Node* toRemove, Node* dummy)
{
    Node* v = toRemove;
    Node* sucessor = successor(toRemove, dummy);

    if (toRemove->leftSon == dummy)
    {
        root = transplant(root, toRemove, toRemove->rightSon);
    } else if(toRemove->rightSon == dummy)
    {
        root = transplant(root, toRemove, toRemove->leftSon);
    } else
    {
        Node* y = minimum(toRemove->rightSon, dummy);
        if (y->father != toRemove)
        {
            root = transplant(root, y, y->rightSon);
            y->rightSon = toRemove->rightSon;
            y->rightSon->father = y;
        }
        root = transplant(root, toRemove, y);
        y->leftSon = toRemove->leftSon;
        y->leftSon->father = y;
    }
    free(toRemove);
    if (sucessor == NULL)
    {
        return root;
    }
    if(v->color == 0 && sucessor->color == 1) // situacao 2
    {
        sucessor->color = 0;
    } else if (v->color == 0 && sucessor->color == 0) // situacao 3
    {
        root = situation3(root, sucessor);
    } else if (v->color == 1 && sucessor->color == 0) // situacao 4
    {
        sucessor->color = 1;
        root = situation3(root, successor(sucessor, dummy));
    }
    return root;
}

Node* search(Node* root, int key, Node* dummy)
{
    Node* searched = root;
    while(searched != dummy && key != searched->key)
    {
        if(key < searched->key)
        {
            searched = searched->leftSon;
        } else
        {
            searched = searched->rightSon;
        }
    }
    return searched;
}

Node* minimum(Node* treeNode, Node* dummy)
{
    if (treeNode == dummy)
    {
        return NULL;
    }
    while (treeNode->leftSon != dummy)
    {
        treeNode = treeNode->leftSon;
    }
    return treeNode;
}

Node* maximum(Node* treeNode, Node* dummy)
{
    if (treeNode == dummy)
    {
        return NULL;
    }
    while (treeNode->rightSon != dummy)
    {
        treeNode = treeNode->rightSon;
    }
    return treeNode;
}

Node* successor(Node* treeNode, Node* dummy)
{
    if (treeNode == dummy)
    {
        return NULL;
    }
    if (treeNode->rightSon != dummy)
    {
        return minimum(treeNode->rightSon, dummy);
    }
    Node* sucessor = treeNode->father;
    while (sucessor != NULL && treeNode == sucessor->rightSon)
    {
        treeNode = sucessor;
        sucessor = sucessor->father;
    }
    return sucessor;
}

Node* predecessor(Node* treeNode, Node* dummy)
{
    if (treeNode == dummy)
    {
        return NULL;
    }
    if(treeNode->leftSon != dummy)
    {
        return maximum(treeNode->leftSon, dummy);
    }
    Node* predecesor = treeNode->father;
    while (predecesor != NULL && treeNode == predecesor->leftSon)
    {
        treeNode = predecesor;
        predecesor = predecesor->father;
    }
    return predecesor;
}

void printTree(Node* root, Node* dummy)
{
    if (root == dummy)
        return;
    if (root->leftSon == dummy && root->rightSon == dummy)
        printf("key: %d \t             \t              \t color: %d\n", root->key, root->color);
    else if (root->rightSon != dummy && root->leftSon == dummy)
        printf("key: %d \t             \t rightSon: %d \t color: %d\n", root->key, root->rightSon->key, root->color);
    else if (root->leftSon != dummy && root->rightSon == dummy)
        printf("key: %d \t leftSon: %d \t              \t color: %d\n", root->key, root->leftSon->key, root->color);
    else if (root->rightSon != dummy && root->leftSon != dummy)
        printf("key: %d \t leftSon: %d \t rightSon: %d \t color: %d\n", root->key, root->leftSon->key, root->rightSon->key, root->color);
    printTree(root->leftSon, dummy);
    printTree(root->rightSon, dummy);
}

Node* balanceTree(Node* root, Node* node)
{
    if (root == node) {
        root->color = 0;
        return root;
    }
    Node* v = node->father;
    if (v == NULL)
        return root;
    Node* w = v->father;
    if (w == NULL)
        return root;

    if(v->color == 1)
    {
        Node *t;
        if (v == w->leftSon)
        {
            t = w->rightSon;
        } else {
            t = w->leftSon;
        }
        if (t->color == 1)
        {
            v->color = 0;
            t->color = 0;
            w->color = 1;
            root = balanceTree(root, w);
        } else {
            if (node == v->leftSon && v == w->leftSon)
            {
                root = rightRotation(root, w);
                v->color = 0;
                w->color = 1;
            } else if (node == v->leftSon && v == w->rightSon)
            {
                root = doubleLeftRotation(root, w);
                node->color = 0;
                w->color = 1;
            } else if (node == v->rightSon && v == w->rightSon)
            {
                root = leftRotation(root, w);
                v->color = 0;
                w->color = 1;
            } else if(node == v->rightSon && v == w->leftSon)
            {
                root = doubleRightRotation(root, w);
                node->color = 0;
                w->color = 1;
            }
        }
    }
    return root;
}

Node* leftRotation(Node* root, Node* toRotate)
{
    Node* v = toRotate;
    Node* u = toRotate->rightSon;
    root = transplant(root, v, u);
    v->father = u;
    v->rightSon = u->leftSon;
    u->leftSon = v;
    return root;
}

Node* rightRotation(Node* root, Node* toRotate)
{
    Node* p = toRotate;
    Node* u = toRotate->leftSon;
    root = transplant(root, p, u);
    p->father = u;
    p->leftSon = u->rightSon;
    u->rightSon = p;
    return root;
}

Node* doubleLeftRotation(Node* root, Node* toRotate)
{
    root = rightRotation(root, toRotate->rightSon);
    root = leftRotation(root, toRotate);
    return root;
}

Node* doubleRightRotation(Node* root, Node* toRotate)
{
    root = leftRotation(root, toRotate->leftSon);
    root = rightRotation(root, toRotate);
    return root;
}

void preOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->key);
    preOrder(root->leftSon);
    preOrder(root->rightSon);
}

void posOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    posOrder(root->leftSon);
    posOrder(root->rightSon);
    printf("%d/n", root->key);
}
void inOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->leftSon);
    printf("%d\n", root->key);
    inOrder(root->rightSon);
}

Node* createDummy(Node* dummy)
{
    dummy = malloc(sizeof(Node));
    dummy->color = 0;
    dummy->leftSon = dummy->leftSon = dummy->father = NULL;
    return dummy;
}

Node* createNode(Node* dummy, int key)
{
    Node* node;
    node = malloc(sizeof(Node));
    node->key = key;
    node->leftSon = node->rightSon = dummy;
    node->father = NULL;
    node->color = 1;
    return node;
}
