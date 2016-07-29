#include <stdlib.h>

/* select method */
void selectSort(int array[], int p, int q)
{
    int i, j, k;
    for (i = p; i < q; i++) {
        k = i;
        for (j = i+1; j <= q; j++) {
            if (array[j] < array[k]) {
                k = j;
            }
        }

        if (k != i) {
            array[i] ^= array[k];
            array[k] ^= array[i];
            array[i] ^= array[k];
        }
    }
}

/* improve select method */
void select2Sort(int array[], int p, int q)
{
    int i, j, k, min, max;
    for (i = p, j = q; j > i; i++, j--) {
        if (array[j] < array[i]) {
            array[j] ^= array[i];
            array[i] ^= array[j];
            array[j] ^= array[i];
        }
        min = i;
        max = j;
        for (k = i+1; k < j; k++) {
            if (array[k] < array[min]) {
                min = k;
            }
            if (array[k] > array[max]) {
                max = k;
            }
        }

        if (min != i) {
            array[i] ^= array[min];
            array[min] ^= array[i];
            array[i] ^= array[min];
        }
        if (max != j) {
            array[j] ^= array[max];
            array[max] ^= array[j];
            array[j] ^= array[max];
        }
    }
}

/* insert method */
void insertSort(int array[], int p, int q)
{
    int i, j, x;
    for (i = p+1; i <= q; i++) {
        if (array[i] >= array[i-1]) continue;
        x = array[i];
        array[i] = array[i-1];
        j = i-1;
        while (j > p && x < array[j-1]) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = x;
    }
}

/* bubble method */
void bubbleSort(int array[], int p, int q)
{
    int i, j, sorted;
    for (i = q; i > p; i--) {
        sorted = 1;
        for (j = p; j < i; j++) {
            if (array[j+1] > array[j]) {
                sorted = 0;
                array[j+1] ^= array[j];
                array[j] ^= array[j+1];
                array[j+1] ^= array[j];
            }
        }
        if (sorted) break;
    }
}

/* shell method */
void shellInsertSort(int array[], int p, int q, int n)
{
    int i, j, x;
    for (i = p+n; i <= q; i++) {
        if (array[i] >= array[i-n]) continue;
        x = array[i];
        array[i] = array[i-n];
        j = i-n;
        while (j >= p+n && x < array[j-n]) {
            array[j] = array[j-n];
            j-=n;
        }
        array[j] = x;
    }
}

void shellSort(int array[], int p, int q)
{
    int n = q-p+1;
    while ((n>>=1) > 0) {
        shellInsertSort(array, p, q, n);
    }
}

/* merge sort */
void merge(int array[], int p, int r, int q)
{
    int *L = malloc(r-p+1);
    int *R = malloc(q-r);

    int i;
    for (i = p; i <= r; i++) {
        L[i-p] = array[i];
    }

    for (i = r+1; i <= q; i++) {
        R[i-r-1] = array[i];
    }

    int j = 0, k = 0;
    i = p;
    while (j < r-p+1 && k < q-r) {
        if (L[j] < R[k]) {
            array[i] = L[j];
            j++;
        } else {
            array[i] = R[k];
            k++;
        }
        i++;
    }

    if (j == r-p+1) {
        while (k < q-r) {
            array[i++] = R[k++];
        }
    } else {
        while (j < r-p+1) {
            array[i++] = L[j++];
        }
    }

    free(L);
    free(R);
}

void mergeSort(int array[], int p, int q)
{
    if (q > p) {
        int r = (p+q)/2;
        mergeSort(array, p, r);
        mergeSort(array, r+1, q);
        merge(array, p, r, q);
    }
}

/* quick sort */
int quick(int array[], int p, int q)
{
    int key = array[p];
    int i, j;
    for (i = p+1, j = p+1; i <= q; i++) {
        if (array[i] <= key) {
            if (i > j) {
                array[i] ^= array[j];
                array[j] ^= array[i];
                array[i] ^= array[j];
            }
            j++;
        }
    }
    j--;
    if (j > p) {
        array[p] ^= array[j];
        array[j] ^= array[p];
        array[p] ^= array[j];
    }
    return j;
}

void quickSort(int array[], int p, int q)
{
    if (q > p) {
        int r = quick(array, p, q);
        quickSort(array, p, r-1);
        quickSort(array, r+1, q);
    }
}
