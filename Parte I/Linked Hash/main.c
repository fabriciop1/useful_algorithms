#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "list.h"

int main()
{
    int select, k;
    initializeTable(T);
    do
    {
        printf("\n(1) - Hash Insert\n(2) - Hash Delete\n(3) - Hash Print\n(4) - Hash Free\n(0) - Exit\nChoose your option: \n");
        scanf("%d", &select);

        switch(select)
        {
            case 0:
                break;
            case 1:
                printf("\nInsert the key: ");
                scanf("%d", &k);
                hash_insert(T, k);
                break;
            case 2:
                printf("\nInsert the key: ");
                scanf("%d", &k);
                hash_delete(T, k);
                break;
            case 3:
                hash_print(T);
                break;
            case 4:
                hash_free_all(T);
                initializeTable(T);
                break;
            default:
                printf("\nWrong. Try again.\n");
                break;
        }
    }while (select != 0);

    hash_free_all(T);

    return 0;
}
