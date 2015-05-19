#include "header.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int select, size, value, key, extracted, i, sizeTemp;
    int* sortedHeap;

    printf("#### BINARY HEAP ####\n");

    heap = initializeHeap(heap);

    if (heap == NULL) {
        printf("\nERROR. Memory is not enough. Program ended.\n");
        return -1;
    }

    do {
        printf("\nSelect the heap type: \n(0) - Max Heap\n(1) - Min Heap\n");
        scanf("%d", &type);
        if (type < 0 || type > 1) {
            printf("\nInvalid option. Try again.\n");
        }
    } while (type < 0 || type > 1);

    printf("\nType the size of the heap: \n");
    scanf("%d", &size);

    printf("Type the values(separated by one space bar): \n");
    for (i = 1; i <= size; i++)
    {
        scanf("%d", &heap[i]);
    }

    buildHeap(heap, size);
    printf("\nHeap done.\n\n");

    do
    {
        printf("Select an option: \n(1) - Heap Insert\n(2) - Heap Extract\n(3) - Print Heap\n(4) - Heap Sort\n(0) - Exit\n");
        scanf("%d", &select);
        switch(select) {
            case 0:
                break;
            case 1:
                printf("\nInsert the new key: ");
                scanf("%d", &key);
                if (heapSize == heapLength) {
                    heap = adjustLength(heap);
                    if (heap == NULL) {
                        printf("\n\nERROR. Out of Memory.\n\n");
                        break;
                    }
                }
                heapInsert(heap, key);
                printf("\n\nElement Inserted.\n\n");
                break;
            case 2:
                extracted = heapExtract(heap);
                printf("\n\nExtracted element: %d\nHeap Updated.\n\n", extracted);
                break;
            case 3:
                printHeap(heap);
                break;
            case 4:
                heapSort(heap);
                printf("\nHeap Sorted.\nVector = ");
                heapSize = size;
                for(i = 1; i <= size; i++)
                {
                    printf("%d ", heap[i]);
                }
                printf("\n\nExiting program...\n");
                select = 0;
		break;
            default:
                printf("\n\nTry again. Value is not valid.\n\n");
                break;
        }
    } while (select != 0);

    deleteHeap(heap);

    return 0;
}
