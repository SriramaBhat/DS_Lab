/* Program to demonstrate dynamic memory allocation with array operations */
#include <stdio.h>
#include <stdlib.h>

void read(int[], int);
void display(int[], int);
void sort(int *, int);
int search(int[], int, int);
void insert(int *, int *, int, int, int **);
void delete_pos(int *, int *, int, int **);
void delete_ele(int *, int *, int, int **);

void main()
{
    int *arr = NULL, i, n, choice, key, val, pos;
    for (;;)
    {
        printf("\nThe following operations can be carried out on the array:\n");
        printf("\n1)Reading the array elements\n2)Displaying the array elements\n3)Sorting the array elements\n");
        printf("4)Searching for the key in the arrary\n5)Inserting an element to the array\n6)Deleting an element from the array by it's position\n");
        printf("7)Deleting an array element on it's value\n8)Exit\n");
        printf("\nPlease enter your choice\n");
        fflush(stdin);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nPlease enter the size of the array:\n");
            scanf("%d", &n);
            if (arr == NULL)
            {
                arr = (int *)calloc(n, sizeof(int));
            }
            else
            {
                arr = (int *)realloc(arr, n * sizeof(int));
            }
            if (arr == NULL)
            {
                printf("Could not allocate required memory\n");
                exit(0);
            }
            read(arr, n);
            break;

        case 2:
            display(arr, n);
            break;

        case 3:
            sort(arr, n);
            break;

        case 4:
            printf("\nPlease enter the key to be searched:\n");
            scanf("%d", &key);
            pos = search(arr, n, key);
            if (pos >= 0)
            {
                printf("\nThe search is successful and the key is found in %d location\n", pos + 1);
            }
            else
            {

                printf("\nThe search is unsuccessful\n");
            }
            break;

        case 5:
            printf("\nPlease enter the value to be inserted:\n");
            scanf("%d", &val);
            printf("\nPlease enter the position to be inserted:\n");
            scanf("%d", &pos);
            insert(arr, &n, val, pos, &arr);
            break;

        case 6:
            printf("\nPlease enter the position of the value to be deleted:\n");
            scanf("%d", &pos);
            delete_pos(arr, &n, pos, &arr);
            break;

        case 7:
            printf("\nPlease enter the value of the element to be deleted:\n");
            scanf("%d", &val);
            delete_ele(arr, &n, val, &arr);
            break;

        case 8:
            exit(0);
        default:
            printf("Invalid choice");
            exit(0);
        }
    }
}

void read(int a[], int n)
{
    int i;
    printf("\nPlease enter the %d array elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    return;
}

void display(int a[], int n)
{
    int i;
    printf("\nThe array elements are as follows:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    return;
}

void sort(int *a, int n)
{
    int i, j, flag = 0, temp = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                temp = *(a + j);
                *(a + j) = *((a + j) + 1);
                *((a + j) + 1) = temp;
                flag = 1;
            }
        }

        if (flag == 0)
        {
            break;
        }
    }

    return;
}

int search(int a[], int n, int key)
{
    int i, p;
    for (i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            p = i;
            break;
        }
        else
        {
            p = -1;
        }
    }
    return p;
}

void insert(int *ptr, int *a, int val, int pos, int **arr)
{
    int i;
    *arr = (int *)realloc(ptr, *a * sizeof(int));
    for (i = *(a - 1); i >= pos; i--)
    {
        *((ptr + i) + 1) = *(ptr + i);
    }
    *(ptr + pos) = val;
    (*a)++;
    if (*arr == NULL)
    {
        printf("Could not re-allocate required memory\n");
        exit(1);
    }
    return;
}

void delete_pos(int *ptr, int *a, int pos, int **arr)
{
    int i;
    for (i = pos; i < *a; i++)
    {
        *(ptr + i) = *((ptr + i) + 1);
    }
    --(*a);
    *arr = realloc(ptr, *a * sizeof(int));
    return;
}

void delete_ele(int *ptr, int *a, int ele, int **arr)
{
    int i, pos;
    pos = search(ptr, *a, ele);
    if (pos == -1)
    {
        printf("\nThe element entered does not exist\n");
        return;
    }
    else
    {
        for (i = pos; i < *a; i++)
        {
            *(ptr + i) = *((ptr + i) + 1);
        }
        --(*a);
        *arr = realloc(ptr, *a * sizeof(int));
        return;
    }
}