#include <stdio.h>
#include <stdlib.h>
#include "BSTreeHeader.h"

Node* insert(Node* root, Node *newNode)
{
    Node *node = NULL;
    Node *x = root;
    while (x != NULL)
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

Node* removeNode(Node* root, Node* toRemove)
{
    if (toRemove->leftSon == NULL)
    {
        root = transplant(root, toRemove, toRemove->rightSon);
    } else if(toRemove->rightSon == NULL)
    {
        root = transplant(root, toRemove, toRemove->leftSon);
    } else
    {
        Node* y = minimum(toRemove->rightSon);
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
    return root;
}

Node* search(Node* root, int key)
{
    Node* searched = root;
    while(searched != NULL && key != searched->key)
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

Node* minimum(Node* treeNode)
{
    if (treeNode == NULL)
    {
        return NULL;
    }
    while (treeNode->leftSon != NULL)
    {
        treeNode = treeNode->leftSon;
    }
    return treeNode;
}

Node* maximum(Node* treeNode)
{
    if (treeNode == NULL)
    {
        return NULL;
    }
    while (treeNode->rightSon != NULL)
    {
        treeNode = treeNode->rightSon;
    }
    return treeNode;
}

Node* successor(Node* treeNode)
{
    if (treeNode == NULL)
    {
        return NULL;
    }
    if (treeNode->rightSon != NULL)
    {
        return minimum(treeNode->rightSon);
    }
    Node* sucessor = treeNode->father;
    while (sucessor != NULL && treeNode == sucessor->rightSon)
    {
        treeNode = sucessor;
        sucessor = sucessor->father;
    }
    return sucessor;
}

Node* predecessor(Node* treeNode)
{
    if (treeNode == NULL)
    {
        return NULL;
    }
    if(treeNode->leftSon != NULL)
    {
        return maximum(treeNode->leftSon);
    }
    Node* predecesor = treeNode->father;
    while (predecesor != NULL && treeNode == predecesor->leftSon)
    {
        treeNode = predecesor;
        predecesor = predecesor->father;
    }
    return predecesor;
}

void printTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->key);
    printTree(root->leftSon);
    printTree(root->rightSon);
}
