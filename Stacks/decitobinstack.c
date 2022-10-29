/* Program to convert the given decimal number to it's binary form */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stackstruct
{
    int *stack;
    int top;
    int size;
}bin;

void push(int rem)
{
    bin.top++;
    bin.size++;
    bin.stack = realloc(bin.stack, bin.size*sizeof(int));
    *(bin.stack+bin.top) = rem;
    return;
}

int pop()
{
    int ele;
    ele = *(bin.stack+bin.top);
    bin.size--;
    bin.top--;
    bin.stack = realloc(bin.stack, bin.size*sizeof(int));
    return ele;
}

void display()
{
    int i;
    printf("\nThe binary form of the given number is:\n");
    for(i=bin.top; i>=0; i--)
    {
        printf("%d", *(bin.stack+i));
    }
    return;
}

void main()
{
    bin.top = -1;
    bin.size = 0;
    bin.stack = NULL;
    int deci, rem;
    printf("\nPlease enter the number to converted\n");
    scanf("%d", &deci);
    while(deci != 0)
    {
        rem = deci%2;
        push(rem);
        deci = deci/2;
    }
    display();
}