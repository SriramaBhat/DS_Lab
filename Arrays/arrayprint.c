/* Program to scan and print the array elements using pointers */
#include<stdio.h>
void main()
{
    int i, n, arr[20];
    int *ptr;
    ptr = arr;
    printf("\nPlease enter the size of the array:\n");
    scanf("%d", &n);
    printf("\nPlease enter the %d array elemnts:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", ptr+i);
    }
    printf("\nThe array elements are:\n");
    for(i=0; i<n; i++)
    {
        printf("%d\n", *(ptr+i));
    }
}