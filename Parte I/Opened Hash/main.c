#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    initialize(table);
    int select, key;
    do
    {
        printf("HASH TABLE - ENDERECAMENTO ABERTO - TENTATIVA LINEAR\n");
        printf("(1) - Hash Insert\n(2) - Hash Remove\n(3) - Hash Print\n(0) - Exit\n");
        scanf("%d", &select);
        switch(select)
        {
            case 0:
                break;
            case 1:
                printf("\nInsert they key: ");
                scanf("%d", &key);
                insert(table, key);
                break;
            case 2:
                printf("\nInsert the key: ");
                scanf("%d", &key);
                removePos(table, key);
                break;
            case 3:
                print(table);
                break;
            default:
                printf("\nERROR. Try Again.\n");
                break;
        }
    } while (select != 0);
    //free(table);
    return 0;
}
