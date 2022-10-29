/* Program to implement stack using linked lists */
#include <stdio.h>
#include <stdlib.h>

int top = -1;

struct node
{
    int info;
    struct node* link;
};

typedef struct node* NODE;


NODE push(NODE stack, int item)
{
    top++;
    NODE new = (NODE)malloc(sizeof(struct node));
    new->info=item;
    if (top==-1)
    {
        new->link = NULL;
        return new;
    }
    new->link = stack;
    return new;
}

NODE pop(NODE stack)
{
    if (top==-1)
    {
        printf("\nStack Empty\n");
        return NULL;
    }
    NODE ptr = stack;
    stack = stack->link;
    free(ptr);
    top--;
    return stack;
}

void peek(NODE stack)
{
    if (top==-1)
    {
        printf("Stack Empty\n");
        return;
    }
    printf("\nThe top element is:\n");
    printf("%d",stack->info);
}

void display(NODE stack)
{
    if (top==-1)
    {
        printf("Stack Empty\n");
        return;
    }
    NODE temp = stack;
    printf("\nElements of stack are:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->link;
    }
}


void main()
{
    NODE stack = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1)Push\n2)Pop\n3)Peek\n4)Display\n5)Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nEnter the value to be pushed\n"); 
                   scanf("%d", &item);
                   stack = push(stack, item);
                   break;

            case 2: stack = pop(stack);
                   break;

            case 3: peek(stack);
                   break;

            case 4: display(stack);
                   break;

            default: exit(0);
        }
    }
}