#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


typedef struct Node
{
    struct Node* next;
    int key;
} Node;

typedef struct Queue
{
    struct Node* root;
} Queue;

void QueueAdd(Queue*, int);
Node* QueuePop(Queue*);
int QueueIsEmpty(Queue*);
Queue* initializeQueue();
void excludeQueue(Queue*);
void printQueue(Queue*);
Node* QueueSearchNode(Queue*, int);


#endif // QUEUE_H_INCLUDED
