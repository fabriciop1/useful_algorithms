#include<stdlib.h>
#include<stdio.h>
#include "queue.h"

void QueueAdd(Queue* queue, int key)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (QueueIsEmpty(queue) == 1)
    {
        queue->root = newNode;
        return;
    }

    Node* node = queue->root;

    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = newNode;
}

Node* QueuePop(Queue* queue)
{
    if(QueueIsEmpty(queue) == 1)
    {
        return NULL;
    }
    Node* node = queue->root;
    queue->root = node->next;
    return node;
}

int QueueIsEmpty(Queue* queue)
{
    if(queue->root == NULL)
    {
        return 1;
    }
    return 0;
}

Queue* initializeQueue()
{
    Queue* queue = malloc(sizeof(Queue));
    queue->root = NULL;
    return queue;
}

void excludeQueue(Queue* queue)
{
    Node* node;
    Node* next;

    if (QueueIsEmpty(queue) == 0)
    {
        node = queue->root;
        while(node != NULL)
        {
            next = node->next;
            free(node);
            node = next;
        }
    }
}

void printQueue(Queue* queue)
{
    if(QueueIsEmpty(queue) != 1)
    {
        Node* node = queue->root;

        while(node != NULL)
        {
            printf("%d ", node->key);
            node = node->next;
        }
    }
}

Node* QueueSearchNode(Queue* queue, int key)
{
    if (QueueIsEmpty(queue) == 1)
    {
        return NULL;
    }

    Node* node = queue->root;
    while(node != NULL && node->key != key)
    {
        node = node->next;
    }
    return node;
}
