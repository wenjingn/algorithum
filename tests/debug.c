#include <stdio.h>
#include "../time.c"

void printArray(int array[], int n, char *fmt)
{
    int i;
    for (i = 0; i < n; i++) {
        printf(fmt, array[i]);
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

int isSorted(int array[], int n)
{
    int i, ret = 1;
    for (i = 1; i < n; i++) {
        if (array[i] < array[i-1]) {
            ret = 0;
            break;
        }
    }

    return ret;
}
