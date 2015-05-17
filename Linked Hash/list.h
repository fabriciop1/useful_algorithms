#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*###################### Linked List Header ###########################*/
typedef struct Node{
    int key;
    struct Node* next;
} Node;

typedef struct {
    struct Node* root;
} List;

void insert(List*, int);
void removeNode(List*, int);
Node* search(List*, int);
List* initialize();
void exclude(List*);
void print(List*);
/*########################## Linked List Header ###########################*/


#endif // HEADER_H_INCLUDED
