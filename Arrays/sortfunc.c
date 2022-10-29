#include<stdio.h>

void sort(int a[], int n)
{
    int i, j, flag=0, temp=0, *ptr;
    ptr = a;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if (*(ptr+i)>*((ptr+i)+1))
            {
                temp = *(ptr+i);
                *(ptr+i) = *((ptr+i)+1);
                *((ptr+i)+1) = temp;
                flag = 1;
            }
        }

        if(flag == 0)
        {
            break;
        }
    }

    return;
}

void main()
{
    int arr[20], n, i;
    printf("\nEnter array size\n");
    scanf("%d", &n);
    printf("\nArray elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", arr[i]);
    }

    sort(arr, n);
    printf("\nSortedd array\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t");
    }
}