/* Program to demonstrate operations on an statically allocated stack */
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10

struct stack
{
int stack[CAPACITY];
int top;
}s;


void push()
{
    int item;
    if(s.top >= CAPACITY-1)
    {
        printf("\nSTACK FULL\n");
        return;
    }
    else
    {
        printf("\nEnter element to be pushed\n");
        scanf("%d", &item);
        s.top++;
        s.stack[s.top] = item;
        return;
    }
}

void pop()
{
    int item;
    if(s.top == -1)
    {
        printf("\nSTACK EMPTY\n");
        return;
    }
    else
    {
     //    item = s.stack[s.top]; // Write only if item is required for some other operation
        s.top--;
    }
}

void peek()
{
    if (s.top == -1)
    {
        printf("\nStack is Empty\n");
        return;
    }
    else
    {
        printf("\nThe top element is:\n");
        printf("%d", s.stack[s.top]);
    }
}

void display()
{
    int i;
    if(s.top == -1)
    {
        printf("\nStack is Empty\n");
        return;
    }
    printf("\nThe elements of stack are:\n");
    for(i=s.top; i>=0; i--)
    {
        printf("%d\t", s.stack[i]);
    }
    return;
}

void main()
{
    int choice;
    s.top = -1;
    for(;;)
    {
        printf("\n1)Push\n2)Pop\n3)Peek\n4)Display\n5)Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push();
                   break;

            case 2: pop();
                   break;

            case 3: peek();
                   break;

            case 4: display();
                   break;

            default: exit(0);
        }
    }
}
