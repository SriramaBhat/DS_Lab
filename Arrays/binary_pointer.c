/* Program to demonstrate binary search using pointers */
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int arr[20], i, n, key, mid, high, low;
    int *ptr;
    ptr = arr;
    printf("\nPlease enter the size of the array:\n");
    scanf("%d", &n);
    printf("\nPlease enter the %d array elements in sorted manner:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", ptr+i);
    }
    printf("\nPlease enter the key to be searched:\n");
    scanf("%d", &key);
    low = 0;
    high = n-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(key == *(ptr+mid))
        {
            printf("\nThe search is successful and key is found in %d location\n", mid+1);
            exit(0);
        }
        if(key>*(ptr+mid))
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    printf("\nSearch unsuccessful\n");
}