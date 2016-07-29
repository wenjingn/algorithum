#include "debug.c"
#include "../sort.c"

#define LEN 10
int main()
{
    int array[LEN] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    randArray(array, LEN, 10, 99);
    printArray(array, LEN);
    //merge(array, 0, 4, 9);
    select2Sort(array, 0, LEN-1);
    printArray(array, LEN);
}
