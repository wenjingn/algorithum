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
            if (array[j+1] < array[j]) {
                sorted = 0;
                int tmp = array[j+1];
                array[j+1] = array[j];
                array[j] = tmp;
            }
        }
        if (sorted) break;
    }
}

void bubble2Sort(int array[], int p, int q)
{
    int i = q, j;
    while (i > p) {
        int pos = p;
        for (j = p; j < i; j++) {
            if (array[j+1] < array[j]) {
                int tmp = array[j+1];
                array[j+1] = array[j];
                array[j] = tmp;
                pos = j;
            }
        }
        i = pos;
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
    int *L = calloc(r-p+1, sizeof(int));
    int *R = calloc(q-r, sizeof(int));

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

/* heap sort */
void heapAdjust(int array[], int p, int q, int i)
{
    int child;
    while ((child = 2*i-p+1) <= q) {
        if (child < q && array[child+1] > array[child]) child++;
        if (array[child] > array[i]) {
            int tmp = array[i];
            array[i] = array[child];
            array[child] = tmp;
            i = child;
        } else {
            break;
        }
    }
}

void heapSort(int array[], int p, int q)
{
    int i;
    for (i = (p+q-1)/2; i >= 0; i--) {
        heapAdjust(array, p, q, i);
    }

    for (i = q; i > p; i--) {
        int tmp = array[p];
        array[p] = array[i];
        array[i] = tmp;
        heapAdjust(array, p, i-1, p);
    }
}

/* count sort */
void countSort(int array[], int p, int q, int min, int max)
{
    int range = max-min+1;
    int *C = calloc(range, sizeof(int));
    int i;
    for (i = 0; i < range; i++) {
        C[i] = 0;
    }

    for (i = p; i <= q; i++) {
        C[array[i]-min]++;
    }

    int j = 0;
    for (i = 0; i < range; i++) {
        while (C[i]>0) {
            array[p+j] = min+i;
            j++;
            C[i]--;
        }
    }

    free(C);
}

/* radix sort */
void radixSort(int array[], int l, int b, int r)
{
    int k = 1<<r;
    int m = k - 1;
    int *R = calloc(k, sizeof(int));
    int *C = calloc(l, sizeof(int));
    
    int *A = array;
    int i, pos;
    for (pos = 0; pos < b; pos += r) {
        int c;
        for (i = 0; i < k; i++) {
            R[i] = 0;
        }

        for (i = 0; i < l; i++) {
            c = (A[i]>>pos)&m;
            R[c]++;
        }

        int count = 0;
        for (i = 0; i < k; i++) {
            if (R[i]) {
                count += R[i];
                R[i] = count;
            }
        }

        for (i = l-1; i >= 0; i--) {
            c = (A[i]>>pos)&m;
            R[c]--;
            C[R[c]] = A[i];
        }

        int *tmp = A;
        A = C;
        C = tmp;
    }

    if (A != array) {
        for (i = 0; i < l; i++) {
            array[i] = A[i];
        }
        C = A;
    }

    free(R);
    free(C);
}
