/* Program to show linear search using pointers */
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int arr[20], i, n, key;
    int *ptr;
    ptr = arr;
    printf("\nPlease enter the size of the array:\n");
    scanf("%d", &n);
    printf("\nPlease enter %d array elements:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", ptr+i);
    }
    printf("\nPlease enter the key to be searched:\n");
    scanf("%d", &key);
    for(i=0; i<n; i++)
    {
        if(key == *(ptr+i))
        {
            printf("\nThe search is successful and key is found in location %d\n", i+1);
            exit(0);
        }
    }
    printf("\nThe search is unsuccessful\n");
}