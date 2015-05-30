#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
                                                            /* MULTIPLICATION METHOD */
#define m 4 // potência de 2 (2 elevado 2) para que o cálculo seja mais eficiente
#define A 0.5 // A definido entre 0 e 1
#include "list.h"

/*############################# Hash Header ################################*/
List* T[m]; // The Table

int get_hash_function(int);
void initializeTable(List*[]);
void hash_insert(List*[], int);
Node* hash_search(List*[], int);
void hash_delete(List*[], int);
void hash_free_all(List*[]);

/*############################# Hash Header ################################*/


#endif // HASH_H_INCLUDED
