/* Program to calculate average of the best two marks of the students */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct student
{
    char name[20];
    int rg_no;
    int test1; 
    int test2; 
    int test3;
    float average_marks;
};

typedef struct student stu;

void read(stu *, int);
void display(stu *, int);
void average(stu *, int);
void sort(stu *, int);
int check(stu *ptr);
void swap1(int *, int *);
void swap2(float *, float *);

void main()
{
    stu *ptr;
    int i;
    ptr = NULL;
    int n, choice;
    for(;;)
    {
        printf("\nThe following operations can be performed on the student record\n");
        printf("\n1)Reading the student record\n2)Displaying the student record\n3)Calculating and displaying the average marks of the best two test\n4)Sorting the Student Record\n5)Exit\n");
        printf("\nPlease enter the operations to be performed on the student record\n");
        fflush(stdin);
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1: printf("\nPlease enter the number of students\n");
                    scanf("%d", &n);
                    ptr = (stu *)calloc(n, sizeof(stu));
                    if(ptr == NULL)
                    {
                        printf("\nMemory Error\n");
                        exit(0);
                    }
                    else
                    {
                        read(ptr, n);
                        break;
                    }

            case 2: i = check(ptr);
                    if(i == 1)
                    {
                        printf("\nPlease enter the student record\n");
                        break;
                    }
                    else
                    {
                        display(ptr, n);
                        break;
                    }

            case 3: i = check(ptr);
                    if(i == 1)
                    {
                        printf("\nPlease enter the student record\n");
                        break;
                    }
                    else
                    {
                        average(ptr, n);
                        break;
                    }

            case 4: i = check(ptr);
                    if(i == 1)
                    {
                        printf("\nPlease enter the student record\n");
                        break;
                    }
                    else
                    {
                        sort(ptr, n);
                        break;
                    } 

            default: exit(0);
        }
    }

}

void read(stu *ptr, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nPlease enter the name of the %d student\n", i+1);
        fflush(stdin);
        gets((ptr+i)->name);
        printf("\nPlease enter the register number of the %d student\n", i+1);
        scanf("%d", &(ptr+i)->rg_no);
        printf("\nPlease enter the marks of the first test\n");
        scanf("%d", &(ptr+i)->test1);
        printf("\nPlease enter the marks of the second test\n");
        scanf("%d", &(ptr+i)->test2);
        printf("\nPlease enter the marks of the third test\n");
        scanf("%d", &(ptr+i)->test3);

    }
    return;
}

void display(stu *ptr, int n)
{
    int i;
    printf("\nNAME\t\tREG.NO\t\tTEST1\t\tTEST2\t\tTEST3\t\tAverage Marks\n");
    for(i=0; i<n; i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d", (*(ptr+i)).name, (*(ptr+i)).rg_no, (*(ptr+i)).test1, (*(ptr+i)).test2, (*(ptr+i)).test3);
        if((*(ptr+i)).average_marks == 0)
        {
            printf("\t\tTo be Calculated\n");
        }
        else
        {
            printf("\t\t%.2f\n", (*(ptr+i)).average_marks);
        }
    }
    return;
}

void average(stu *ptr, int n)
{
    int i, min[15], sum[15], best[15];
    for(i=0; i<n; i++)
    {
        sum[i] = ((*(ptr+i)).test1)+((*(ptr+i)).test2)+((*(ptr+i)).test3); 
        min[i] = ((*(ptr+i)).test1 < (*(ptr+i)).test2) ? (*(ptr+i)).test1 : (*(ptr+i)).test2;
        min[i] = ((*(ptr+i)).test3 < min[i]) ? (*(ptr+i)).test3 : min[i];
        best[i] = sum[i] - min[i];
        (ptr+i)->average_marks = (float)best[i] / (float)2;
    }
    display(ptr, n);
}

int check(stu *ptr)
{
    int i;
    if(ptr == NULL)
    {
        i = 1;
    }
    return i;
}

void sort(stu *a, int n)
{
    int i, j, flag=0, choice;
    stu temp;
    printf("\nPlease enter the basis of sorting\n");
    printf("\n1)By name\n2)By Registartion number\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: for(i=0; i<n-1; i++)
                {
                    for(j=0; j<n-1; j++)
                    {
                        if(strcmp(((*(a+j)).name), ((*((a+j)+1)).name)) > 0)
                        {
                            strcpy(temp.name, (*((a+j)-1)).name);
                            strcpy((*((a+j)-1)).name, (*(a+j)).name);
                            strcpy((*(a+j)).name, temp.name);
                            swap1(&(a+j)->rg_no, &((a+j)+1)->rg_no);
                            swap1(&(a+j)->test1, &((a+j)+1)->test1);
                            swap1(&(a+j)->test2, &((a+j)+1)->test2);
                            swap1(&(a+j)->test3, &((a+j)+1)->test3);
                            swap2(&(a+j)->average_marks, &((a+j)+1)->average_marks);
                            flag = 1;
                        }
                    }

                    if(flag == 0)
                    {
                        break;
                    }                    
                }
                break;

        case 2: for(i=0; i<n-1; i++)
                {
                    for(j=0; j<n-1; j++)
                    {
                        if ((*(a+i)).rg_no > (*((a+i)+1)).rg_no)
                        {
                            strcpy(temp.name, (*(a+j)).name);
                            strcpy((*(a+j)).name, (*((a+j)+1)).name);
                            strcpy((*((a+j)+1)).name, temp.name);
                            swap1(&(a+j)->rg_no, &((a+j)+1)->rg_no);
                            swap1(&(a+j)->test1, &((a+j)+1)->test1);
                            swap1(&(a+j)->test2, &((a+j)+1)->test2);
                            swap1(&(a+j)->test3, &((a+j)+1)->test3);
                            swap2(&(a+j)->average_marks, &((a+j)+1)->average_marks);
                            flag = 1;
                        }
                    }

                    if(flag == 0)
                    {
                        break;
                    }
                }
                break;

        default: printf("\nThe choice is not valid\n");
                 break;
    }

    return;
}  

void swap1(int *a, int *b)
{
    int temp=0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(float *a, float *b)
{
    float temp=0;
    temp = *a;
    *a = *b;
    *b = temp;
}