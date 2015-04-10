#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *father;
    struct Node *leftSon;
    struct Node *rightSon;
    int key;
} Node;

Node *T = NULL; //root

Node* insert(Node*, Node*);
Node* transplant(Node*, Node*, Node*);
Node* removeNode(Node*, Node*);
void printTree(Node*);
Node* search(Node*, int);
Node* minimum(Node*);
Node* maximum(Node*);
Node* successor(Node*);
Node* predecessor(Node*);

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
            newNode->leftSon = newNode->rightSon = NULL;
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
            printf("\nMinimum of the tree: %d\n", y->key);
            break;
        case 5:
            y = maximum(T);
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
