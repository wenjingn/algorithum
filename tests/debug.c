#include <stdio.h>
#include "../time.c"

void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void randArray(int array[], int n, int l, int h)
{
    srand(ustime());
    int i;
    for (i = 0; i < n; i++) {
        array[i] = rand()%(h-l+1)+l;
    }
}
