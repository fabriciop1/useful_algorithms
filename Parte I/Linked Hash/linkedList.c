#include "list.h"
#include<stdio.h>
#include<stdlib.h>

void insert(List* list, int key)
{
    Node* root = list->root;
    Node* node;
    node = malloc(sizeof(Node));
    node->next = NULL;
    node->key = key;
    if (list->root == NULL)
    {
        list->root = node;
        return;
    }
    while (root->next != NULL)
    {
        root = root->next;
    }
    root->next = node;
}

Node* search(List* list, int key)
{
    Node* found = list->root;
    while(found != NULL)
    {
        if(found->key == key){
            return found;
        }
        found = found->next;
    }
    return NULL;
}

void removeNode(List* list, int key)
{
    Node* root = list->root;
    Node* previous;
    if (root->key == key)
    {
        list->root = root->next;
        free(root);
        printf("\nRemoved.\n");
        return;
    }

    while(root != NULL && root->key != key)
    {
        previous = root;
        root = root->next;
    }
    previous->next = root->next;
    free(root);
    printf("\nRemoved.\n");
}

List* initialize()
{
    List* linkedList;
    linkedList = malloc(sizeof(List));
    linkedList->root = NULL;
    return linkedList;
}

void print(List* list)
{
    Node* root = list->root;
    if (root == NULL)
    {
        printf("Empty Tree.");
        return;
    }
    while(root != NULL)
    {
        printf("%d ", root->key);
        root = root->next;
    }
}

void exclude(List* list)
{
    Node* current = list->root;
    Node* nextNode;
    while(current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
    printf("\nList excluded.\n");
}
