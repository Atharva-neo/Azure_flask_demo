#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
int main() 
{
    int high, low, mid, p;
    int arr[7];
    printf("%d\n", sizeof(arr)/sizeof(arr[0]));
    printf("Enter the Element to enter in array:");
    for(int i = 0; i < 7; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the Element to be found in array:");
    scanf("%d",&p);
    bool condition = false;
    high = 7 - 1;
    low = 0;
    while(high >= low)
    {
        mid = high + (low - high)/2;
        if(arr[mid] == p)
       {     
        condition = true;
        break;
       }
       else if(arr[mid] > p)
       {
            high = mid - 1;
       }
       else
       {
            low = mid + 1;
       }
    }
    if (condition)
    printf("Element %d found at position %d\n",p,mid);

    else
    printf("Not found");

    return 0;
}