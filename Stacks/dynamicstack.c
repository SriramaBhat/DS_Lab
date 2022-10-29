/* Program to demonstrate operations on an dynamically allocated stack */
#include<stdio.h>
#include<stdlib.h>
struct stacks
{
    int *stack;
    int top;
    int size;
}s;

void push()
{
    int item;
    printf("\nEnter element to be inserted\n");
    scanf("%d", &item);
    s.top++;
    s.size++;
    s.stack = realloc(s.stack, s.size*sizeof(int));
    *(s.stack+s.top) = item;
    return;
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
     //    item = stack[top]; // Write only if item is required for some other operation
        s.top--;
        s.size--;
        s.stack = realloc(s.stack, s.size*sizeof(int));
        return;
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
        printf("%d", *(s.stack+s.top));
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
        printf("%d\t", *(s.stack+i));
    }
    return;
}

void main()
{
    s.top = -1;
    s.size = 0;
    s.stack = NULL;
    int choice;
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