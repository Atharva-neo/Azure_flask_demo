#include <stdio.h>
void merge(int A[], int high, int mid, int low)
{
    int i, j, k;
     i = low;
     k = low;
     j = mid + 1;
     int B[high + 1];
    while(i <= mid && j <= high)
    {
        if(A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }

    }
    while(i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
     while(j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for(int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void merge_sort(int A[],int high, int low)
{
    if(high > low)
    {
        int mid = low + (high - low)/2;
        merge_sort(A, mid, low);
        merge_sort(A, high, mid+1);
        merge(A, high, mid, low);
    }
}
void display(int *A,int n )
{
    for(int i = 0; i <= n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main() 
{
    int A[7] = {8, 5, 1, 98, 90, 1, 23};
    printf("\n---Unsorted Array---\n");
    display(A, 6);
     merge_sort(A,6,0);
     printf("\n---sorted Array---\n");
    display(A, 6);
    return 0;
}