/* Program to convert the given binary number to decimal number */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
    bin.stack = NULL;
    bin.top = -1;
    bin.size = 0;
    int rem, binary, deci=0, junk;
    printf("\nEnter the binary number\n");
    scanf("%d", &binary);
    while(binary != 0)
    {
        rem = binary%10;
        push(rem);
        binary = binary/10;
    }
    while(bin.top != -1)
    {
        deci = deci+(*(bin.stack+bin.top)*pow(2, bin.top));
        junk = pop();
    }
    printf("\nThe decimal number is %d\n", deci);
}