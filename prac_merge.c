#include <stdio.h>

void Merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];
    while(i <= mid && j <= high )
    {
        if(A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
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
    for(int i = low; i < high + 1; i++)
    {
        A[i] = B[i];
    }
}
void Merge_Sort(int A[], int low, int high)
{
    if(high > low)
    {
        int mid = low + (high - low)/2;
        Merge_Sort(A,low, mid);
        Merge_Sort(A,mid + 1, high);
        Merge(A, low, mid, high);
    }
}
void printarray(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main() 
{
    int A[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    int n = 10;
    printf("Inital Array is: \n");
    printarray(A,n);
    printf("Final Array is: \n");
    Merge_Sort(A,0,9);
    printarray(A,n); 
    return 0;
}