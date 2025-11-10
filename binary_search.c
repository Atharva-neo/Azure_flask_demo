#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
int main() 
{
    int high,low,mid;
    int arr [7];
    int p;
    bool condition = false;
    printf("Enter the elements in the array:\n");
    for(int i = 0; i < 7; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to be found: ");
    scanf("%d",&p);
    high = 6;
    low = 0;
    while(high >= low)
    {
        mid = low + (high - low);
        if(arr[mid] == p)
        {
            condition = true;
            break;
        }
        else if(arr[mid] > p)
        {
            high = mid -1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if(condition)
        printf("Element %d is found at index: %d",p,mid);

    else
    {
        printf("Element Not found!");
    }
    return 0;
}