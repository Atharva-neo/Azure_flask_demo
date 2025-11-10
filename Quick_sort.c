#include<stdio.h>

void swap(int *a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printarray(int * A, int n)
{
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int Partition(int A[], int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = A[low];
 do {   
  
    while(i <= high && A[i] < pivot)
    {
        i ++;
    }
    while(j >= low && A[j] > pivot)
    {
        j --;
    }
    if(i < j)
    {
        swap(&A[i], &A[j]);
    }
}while(i < j);
swap(&A[low], &A[j]);
return j;
}
void Quicksort(int A[], int low, int high)
{
    
    if(high > low)
   { 
    int PartitionIndex = Partition(A, low,  high);
    Quicksort( A, low,  PartitionIndex-1);
    Quicksort( A, PartitionIndex+1,  high);
    
    }
}
int main()
{
    int A[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    int n = 10;
    printf("Inital Array is: \n");
    printarray(A,n);
    printf("Sorted Array: \n");
    Quicksort(A, 0, n - 1);
    printarray(A,n);
}