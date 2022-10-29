/* Program to find maximum element in an array and it's position using pointers */
#include<stdio.h>

void main()
{
    int n, i, max, pos, arr[20];
    int *ptr;
    ptr = arr;
    printf("Please enter the size of the array:\n");
    scanf("%d", &n);
    printf("\nPlease enter %d array elements:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", ptr+i);
    }
    max = *ptr;
    pos = 0;
    for(i=0; i<n; i++)
    {
        if(*(ptr+i)>max)
        {
            max = *(ptr+i);
        }
    }
    for(i=0; i<n; i++)
    {
        pos++;
        if(max == *(ptr+i))
        {
            break;
        }
    }
    printf("\nThe biggest element of the array is %d", max);
    printf("\nIt's position is %d", pos);
}