#include "debug.c"
void SelectSort(int r[],int n) {  
    int i ,j , min ,max, tmp;  
    for (i=0 ;i <= n/2;i++) {    
        // 做不超过n/2趟选择排序   
        min = i; max = i ; //分别记录最大和最小关键字记录位置  
        for (j= i+1; j< n-i; j++) {  
            if (r[j] > r[max]) {   
                max = j ; continue ;   
            }    
            if (r[j]< r[min]) {   
                min = j ;   
            }     
        }    
        //该交换操作还可分情况讨论以提高效率  
        tmp = r[i]; r[i] = r[min]; r[min] = tmp;  
        tmp = r[n-i-1]; r[n-i-1] = r[max]; r[max] = tmp;   
        printf("%d min-%d max-%d: ", i, min, max);
        printArray(r, n);
    }   
}  

#define LEN 10
int main()
{
    int array[LEN] = {100, 44, 33, 55, 66, 22, 45, 34, 99, 77};
    //randArray(array, LEN, 10, 99);
    printArray(array, LEN);
    SelectSort(array, LEN);
    printArray(array, LEN);
}
