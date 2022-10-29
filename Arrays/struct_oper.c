/* Program to demonstrate array operations */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct student
{
    char name[20];
    char usn[12];
    char course[20];
    char section;
    int sr_no;
    float cgpa;
};

typedef struct student stu;

void read(stu [], int);
void display(stu [], int);
void sort(stu *, int);
int search(stu[], int, char[]);
void insert(stu *, int *, stu [], int);
void delete_usn(stu *, int *, char[]);

void main()
{
    stu s[20], val[2];
    int i, n, choice, pos;
    char key[12];
    for(;;)
    {
        printf("\nThe following operations can be carried out on the array of structures storing student information:\n");
        printf("\n1)Reading the student information\n2)Displaying the student information\n3)Sorting the student information\n");
        printf("4)Searching for the student information by usn\n5)Inserting an element to the student information\n");
        printf("6)Deleting a student's information by usn\n7)Exit\n");
        printf("\nPlease enter your choice\n");
        fflush(stdin);
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("\nPlease enter the number of students:\n");
                    scanf("%d", &n);
                    read(s, n);
                    break;

            case 2: display(s,n);
                    break;
            
            case 3: sort(s, n);
                    break;

            case 4: printf("\nPlease enter the usn to be searched:\n");
                    gets(key);
                    pos = search(s, n, key);
                    if(pos == -1)
                    {
                        printf("\nThe search is unsuccessful\n");
                    }
                    else
                    {
                        printf("\nThe search is successful and the key is found in %d location\n", pos);
                        strcpy(val[0].name, s[pos].name);
                        strcpy(val[0].usn, s[pos].usn);
                        strcpy(val[0].course,s[pos].course);
                        val[0].section = s[pos].section;
                        val[0].sr_no = s[pos].sr_no;
                        val[0].cgpa = s[pos].cgpa;
                        printf("\nThe student information is as follows\n");
                        display(val, 1);
                    }
                    break;
                    
            case 5: printf("\nPlease enter the Student information to be inserted:\n");
                    read(val, 1);
                    printf("\nPlease enter the position to be inserted:\n");
                    scanf("%d", &pos);
                    insert(s, &n, val, pos);
                    break;
                    
            case 6: printf("\nPlease enter the usn of the student whose information is to be deleted:\n");
                    gets(key);
                    delete_usn(s, &n, key);
                    break;

            case 7: exit(0);
        }
    }
}

void read(stu a[], int n)
{
    int i; 
    for(i=0; i<n; i++)
    {
        fflush(stdin);
        printf("\nPlease enter the name of the %d student\n", i+1);
        gets(a[i].name);
        printf("\nPlease enter the usn of %d student\n", i+1);
        gets(a[i].usn);
        printf("\nPlease enter the course of %d student\n", i+1);
        gets(a[i].course);
        printf("\nPlease enter the section of %d student\n", i+1);
        scanf("%c", &(a[i].section));
        printf("\nPlease enter the SR number of %d student\n", i+1);
        scanf("%d", &a[i].sr_no);
        printf("\nPlease enter the CGPA of %d student\n", i+1);
        scanf("%f", &a[i].cgpa);
    }
    return;
}

void display(stu a[], int n)
{
    int i;
    printf("\nThe student details are as follows:\n");
    for(i=0; i<n; i++)
    {
        printf("\nThe name of the %d student is:\n", i+1);
        puts(a[i].name);
        printf("\nThe usn of %d student is:\n", i+1);
        puts(a[i].usn);
        printf("\nThe course of %d student is:\n", i+1);
        puts(a[i].course);
        printf("\nThe section of %d student is:\n", i+1);
        printf("%c", a[i].section);
        printf("\nThe SR number of %d student is:\n", i+1);
        printf("%d", a[i].sr_no);
        printf("\nThe CGPA of %d student is:\n", i+1);
        printf("%.2f", a[i].cgpa);
    }
    return;
}

void sort(stu *a, int n)
{
    int i, j, flag=0, temp=0, choice;
    char dummy[20];
    printf("\nPlease enter the basis of sorting\n");
    printf("\n1)By name\n2)By USN\n3)By SR number\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: for(i=1; i<n; i++)
                {
                    for(j=1; j<=n-1; j++)
                    {
                        if(strcmp(((*((a+j)-1)).name), ((*(a+j)).name)) > 0)
                        {
                            strcpy(dummy, (*((a+j)-1)).name);
                            strcpy((*((a+j)-1)).name, (*(a+j)).name);
                            strcpy((*(a+j)).name, dummy);
                        }
                    }                    
                }
                break;

        case 2: for(i=1; i<n; i++)
                {
                    for(j=1; j<=n-1; j++)
                    {
                        if(strcmp(((*((a+j)-1)).usn), ((*(a+j)).usn)) > 0)
                        {
                            strcpy(dummy, (*((a+j)-1)).usn);
                            strcpy((*((a+j)-1)).usn, (*(a+j)).usn);
                            strcpy((*(a+j)).usn, dummy);
                        }
                    }                    
                }
                break;

        case 3: for(i=0; i<n-1; i++)
                {
                    for(j=0; j<n-1; j++)
                    {
                        if ((*(a+i)).sr_no > (*((a+i)+1)).sr_no)
                        {
                            temp = (*(a+i)).sr_no;
                            (*(a+i)).sr_no = (*((a+i)+1)).sr_no;
                            (*((a+i)+1)).sr_no = temp;
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

int search(stu a[], int n, char key[12])
{
    int i;
    for(i=0; i<n; i++)
    {
        if(strcmp(key, (a[i].usn)) == 0)
        {
            return i;
            break;
        }
        else
        {
            return -1;
        }
    }
}

void insert(stu *ptr, int *a, stu val[2], int pos)
{
    int i;
    for(i=*(a-1); i>=pos; i--)
    {
        strcpy((*((ptr+i)+1)).name, (*(ptr+i)).name);
        strcpy((*((ptr+i)+1)).usn, (*(ptr+i)).usn);
        strcpy((*((ptr+i)+1)).course, (*(ptr+i)).course);
        (*((ptr+i)+1)).section = (*(ptr+i)).section;
        (*((ptr+i)+1)).sr_no = (*(ptr+i)).sr_no;
        (*((ptr+i)+1)).cgpa = (*(ptr+i)).cgpa; 
    }
    
    strcpy((*(ptr+pos)).name, val[0].name);
    strcpy((*(ptr+pos)).usn, val[0].usn);
    strcpy((*(ptr+i)).course, val[0].course);
    (*(ptr+pos)).section = val[0].section;
    (*(ptr+pos)).sr_no = val[0].sr_no;
    (*(ptr+pos)).cgpa = val[0].cgpa;;
    (*a)++;
    return;
}

void delete_usn(stu *ptr, int *a, char ele[12])
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
            strcpy((*(ptr+i)).name, (*((ptr+i)+1)).name);
            strcpy((*(ptr+i)).usn, (*((ptr+i)+1)).usn);
            strcpy((*(ptr+i)).course, (*((ptr+i)+1)).course);
            (*(ptr+i)).section = (*((ptr+i)+1)).section;
            (*(ptr+i)).sr_no = (*((ptr+i)+1)).sr_no;
            (*(ptr+i)).cgpa = (*((ptr+i)+1)).cgpa;
        }
        --(*a); 
        return;
    }
}