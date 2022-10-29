/* Program to demonstrate array operations */
#include<stdio.h>
#include<stdlib.h>

void read(int[], int); // To read the array
void display(int[], int); // To display the array
void sort(int *, int); // To sort the array
int search(int[], int, int); // To search the array
void insert(int *, int *, int, int); // To insert an element to the array
void delete_pos(int *, int *, int); // To delete an element on the basis of position
void delete_ele(int *, int *, int); // To delete an element on the basis of value

void main()
{
    int arr[20], i, n, choice, key, val, pos;
    for(;;)
    {
        printf("\nThe following operations can be carried out on the array:\n");
        printf("\n1)Reading the array elements\n2)Displaying the array elements\n3)Sorting the array elements\n");
        printf("4)Searching for the key in the arary\n5)Inserting an element to the array\n6)Deleting an element from the array by it's position\n");
        printf("7)Deleting an array element on it's value\n8)Exit\n");
        printf("\nPlease enter your choice\n");
        scanf("%d", &choice); // Choosing choice on the menu

        switch(choice)
        {
            case 1: printf("\nPlease enter the size of the array:\n");
                    scanf("%d", &n);
                    read(arr, n);
                    break;

            case 2: display(arr,n);
                    break;
            
            case 3: sort(arr, n);
                    break;

            case 4: printf("\nPlease enter the key to be searched:\n");
                    scanf("%d", &key);
                    pos = search(arr, n, key);
                    if(pos>0)
                    {
                        printf("\nThe search is successful and the key is found in %d location\n", pos+1);
                    }
                    else
                    {

                        printf("\nThe search is unsuccessful\n");
                    }
                    break;
                    
            case 5: printf("\nPlease enter the value to be inserted:\n");
                    scanf("%d", &val);
                    printf("\nPlease enter the position to be inserted:\n");
                    scanf("%d", &pos);
                    insert(arr, &n, val, pos);
                    break;

            case 6: printf("\nPlease enter the position of the value to be deleted:\n");
                    scanf("%d", &pos);
                    delete_pos(arr, &n, pos);
                    break;
                    
            case 7: printf("\nPlease enter the value of the element to be deleted:\n");
                    scanf("%d", &val);
                    delete_ele(arr, &n, val);
                    break;

            case 8: exit(0);
        }
    }
}

void read(int a[], int n) // Passing by value
{
    int i;
    printf("\nPlease enter the %d array elements:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    return;
}

void display(int a[], int n) // Passing by value
{
    int i;
    printf("\nThe array elements are as follows:\n");
    for(i=0; i<n; i++)
    {
        printf("%d\n", a[i]);
    }
    return;
}

void sort(int *ptr, int n) // Pass by reference
{
    int i, j, flag=0, temp=0;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if (*(ptr+j)>*((ptr+j)+1))
            {
                temp = *(ptr+j);
                *(ptr+j) = *((ptr+j)+1);
                *((ptr+j)+1) = temp;
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

int search(int a[], int n, int key) // Pass by value
{
    int i, p;
    for(i=0; i<n; i++)
    {
        if(key == a[i])
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

void insert(int *ptr, int *a, int val, int pos) // Pass by reference
{
    int i;
    for(i=*(a-1); i>=pos; i--)
    {
        *((ptr+i)+1) = *(ptr+i); 
    }
    *(ptr+pos) = val;
    (*a)++;
    return;
}

void delete_pos(int *ptr, int *a, int pos) // Pass by reference
{
    int i;
    for(i=pos; i<*a; i++)
    {
        *(ptr+i) = *((ptr+i)+1);
    }
    --(*a);
    return;
}

void delete_ele(int *ptr, int *a, int ele) // Pass by reference
{
    int i, pos;
    pos = search(ptr, *a, ele);
    if(pos == -1)
    {
        printf("\nThe element entered does not exist\n");
        return;
    }
    else
    {
        for(i=pos; i<*a; i++)
        {
            *(ptr+i) = *((ptr+i)+1);
        }
        --(*a); 
        return;
    }
}