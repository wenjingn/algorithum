#include "debug.c"
#include "../sort.c"

#define LEN 1000
int main()
{
    unsigned long long start, end;
    int array[LEN] = {33, 72, 68, 65, 76};

    printf("array size: %d\n", LEN);

    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    selectSort(array, 0, LEN-1);
    end = ustime();
    printf("selectSort runtime: %llu\n", end-start);

    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    select2Sort(array, 0, LEN-1);
    end = ustime();
    printf("select2Sort runtime: %llu\n", end-start);

    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    bubbleSort(array, 0, LEN-1);
    end = ustime();
    printf("bubbleSort runtime: %llu\n", end-start);
    
    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    bubble2Sort(array, 0, LEN-1);
    end = ustime();
    printf("bubble2Sort runtime: %llu\n", end-start);
    
    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    insertSort(array, 0, LEN-1);
    end = ustime();
    printf("insertSort runtime: %llu\n", end-start);

    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    shellSort(array, 0, LEN-1);
    end = ustime();
    printf("shellSort runtime: %llu\n", end-start);
    
    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    mergeSort(array, 0, LEN-1);
    end = ustime();
    printf("mergeSort runtime: %llu\n", end-start);

    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    heapSort(array, 0, LEN-1);
    end = ustime();
    printf("heapSort runtime: %llu\n", end-start);

    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    quickSort(array, 0, LEN-1);
    end = ustime();
    printf("quickSort runtime: %llu\n", end-start);
    
    randArray(array, LEN, 0, 65535);
    start = ustime();
    countSort(array, 0, LEN-1, 0, 65535);
    end = ustime();
    printf("countSort runtime: %llu\n", end-start);

    randArray(array, LEN, 0, 2147483647);
    start = ustime();
    radixSort(array, LEN, 32, 8);
    end = ustime();
    printf("radixSort runtime: %llu sorted:%d\n", end-start, isSorted(array, LEN));
}
