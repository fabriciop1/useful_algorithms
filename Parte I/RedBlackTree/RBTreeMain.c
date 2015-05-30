#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Node* T = NULL;
    Node* dummy = createDummy(dummy);
    T = dummy;
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
            Node* newNode = createNode(dummy, key);
            T = insert(T, newNode, dummy);
            printf("\nInserted.\n");
            break;
        case 2:
            printf("Insert the key: ");
            scanf("%d", &key);
            Node* toRemove = search(T, key, dummy);
            if (toRemove == dummy)
            {
                printf("\n404 Not Found.\n");
                break;
            }
            T = removeNode(T, toRemove, dummy);
            printf("\nRemoved\n");
            break;
        case 3:
            printf("\nPrinted Tree: \n");
            printTree(T, dummy);
            break;
        case 4:
            y = minimum(T, dummy);
            if (y == NULL)
            {
                printf("\nEmpty Tree.\n");
                break;
            }
            printf("\nMinimum of the tree: %d\n", y->key);
            break;
        case 5:
            y = maximum(T, dummy);
            if (y == NULL) {
                printf("\nEmpty Tree.\n");
                break;
            }
            printf("\nMaximum of the tree: %d\n", y->key);
            break;
        case 6:
            printf("Insert the key: ");
            scanf("%d", &key);
            y = search(T, key, dummy);
            y = successor(y, dummy);
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
            y = search(T, key, dummy);
            y = predecessor(y, dummy);
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
