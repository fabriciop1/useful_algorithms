#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Node *T = NULL; //root

int main()
{
    int select, key;
    Node *y;
    printf("######## Binary Search Tree - Fabricio Paes - UFRPE ##########\n");

    do {
        printf("\n(1) Insert Node \n(2) Remove Node \n(3) Print Tree\n(4) Tree Minimum\n(5) Tree Maximum\n(6) Successor\n(7) Predecessor\n(0) Exit\n");
        scanf("%d", &select);

        switch(select){
        case 0:
            exit(0);
        case 1:
            printf("Insert the key(number): ");
            scanf("%d", &key);
            Node* newNode = malloc(sizeof(Node));
            newNode->key = key;
            newNode->leftSon = newNode->father = newNode->rightSon = NULL;
            T = insert(T, newNode);
            printf("\nInserted.\n");
            break;
        case 2:
            printf("Insert the key: ");
            scanf("%d", &key);
            Node* toRemove = search(T, key);
            if (toRemove == NULL)
            {
                printf("\n404 Not Found.\n");
                break;
            }
            T = removeNode(T, toRemove);
            printf("\nRemoved\n");
            break;
        case 3:
            printf("\nPrinted Tree: \n");
            printTree(T);
            break;
        case 4:
            y = minimum(T);
            if (y == NULL)
            {
                printf("\nEmpty Tree.\n");
                break;
            }
            printf("\nMinimum of the tree: %d\n", y->key);
            break;
        case 5:
            y = maximum(T);
            if (y == NULL) {
                printf("\nEmpty Tree.\n");
                break;
            }
            printf("\nMaximum of the tree: %d\n", y->key);
            break;
        case 6:
            printf("Insert the key: ");
            scanf("%d", &key);
            y = search(T, key);
            y = successor(y);
            if (y == NULL)
            {
                printf("\n404 Not Found.\n");
                break;
            }
            printf("Successor of %d: %d\n", key, y->key);
            break;
        case 7:
            printf("Insert the key: ");
            scanf("%d", &key);
            y = search(T, key);
            y = predecessor(y);
            if (y == NULL)
            {
                printf("\n404 Not Found.\n");
                break;
            }
            printf("Predecessor of %d: %d\n", key, y->key);
            break;
        }
    } while (select != 0);
    return 0;
}

Node* insert(Node* root, Node *newNode)
{
    Node *node = search(root, newNode->key);
    Node *x = root;
    if (node != NULL)
        return root;
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

    Node* w = newNode;

    while(w != NULL){
        root = balanceTree(root, w);
        w = w->father;
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
    Node* ref = toRemove->father;
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
        ref = y;
    }
    free(toRemove);
    while(ref != NULL) {
        root = balanceTree(root, ref);
        ref = ref->father;
    }
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
    int nodeHeight = height(root->rightSon) - height(root->leftSon); // altura do no a direita menos altura do no a esquerda
    if (root->leftSon==NULL && root->rightSon==NULL)
        printf("key: %d \t hD - hE: %d\n", root->key, nodeHeight);
    if (root->rightSon != NULL && root->leftSon == NULL)
        printf("key: %d \t hD - hE: %d \t rightSon: %d\n", root->key, nodeHeight, root->rightSon->key);
    if(root->leftSon != NULL && root->rightSon == NULL)
        printf("key: %d \t hD - hE: %d \t leftSon: %d\n", root->key, nodeHeight, root->leftSon->key);
    if (root->rightSon != NULL && root->leftSon != NULL)
        printf("key: %d \t hD - hE: %d \t leftSon: %d \t rightSon: %d\n", root->key, nodeHeight, root->leftSon->key, root->rightSon->key);
    printTree(root->leftSon);
    printTree(root->rightSon);
}

int height(Node* node) // altura de um determinado no
{
    if (node == NULL)
        return -1;
    int hLeft = height(node->leftSon);
    int hRight = height(node->rightSon);
    if (hRight > hLeft)
    {
        return hRight+1;
    }
    return hLeft+1;
}

Node* balanceTree(Node* root, Node* node)
{
    int nodeHeight = height(node->rightSon) - height(node->leftSon);
    if (nodeHeight == 2)
    {
        Node* temp = node->rightSon;
        int hTempRightSon = height(temp->rightSon);
        int hTempLeftSon = height(temp->leftSon);
        if (hTempRightSon > hTempLeftSon)
        {
                root = leftRotation(root, node);
                printf("\nLeft Rotation Done.\n");
        } else if (hTempRightSon < hTempLeftSon)
        {
            root = doubleLeftRotation(root, node);
            printf("\nDouble Left Rotation Done. \n");
        }
    } else if (nodeHeight == -2)
    {
        Node* temp = node->leftSon;
        int hTempRightSon = height(temp->rightSon);
        int hTempLeftSon = height(temp->leftSon);
        if(hTempLeftSon > hTempRightSon)
        {
            root = rightRotation(root, node);
            printf("\nRight Rotation Done. \n");
        } else if (hTempLeftSon < hTempRightSon)
        {
            root = doubleRightRotation(root, node);
            printf("\nDouble Right Rotation Done. \n");
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
