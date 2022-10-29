/* Program to demonstrate the operations on a simple queue */
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10

struct simplequeue
{
    int queue[CAPACITY];
    int front, rear;
};
typedef struct simplequeue SQ; 

void enQueue(SQ *q, int item)
{
    if(q->rear == (CAPACITY - 1))
    {
        printf("\nQueue Overflow\n");
        return;
    }
    else
    {
        q->queue[++q->rear] = item;
        if(q->front == -1)
        {
            q->front = 0;
        }
        return;
    }
    
}

int deQueue(SQ *q)
{
    if((q->front > q->rear) || (q->front == -1))
    {
        printf("\nQueue Empty\n");
        return -1;
    }
    else
    {
        int ele;
        ele = q->queue[q->front++];
        printf("\nThe element deleted is %d\n", ele);
        return ele;
    }
}

void display(SQ *q)
{
    if((q->front > q->rear) || (q->front == -1))
    {
        printf("\nQueue Empty\n");
        return;
    }
    else
    {
        int i;
        for(i=q->front; i<=q->rear; i++)
        {
            printf("%d\t", q->queue[i]);
        }
        return;
    }
}

void main()
{
    int item, ele, choice;
    SQ *q;
    q->front = q->rear = -1;
    for(;;)
    {
        printf("\n1)enQueue\n2)deQueue\n3)Display\n4)Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1 : printf("\nEnter the element to be inserted\n");
                    scanf("%d", &item);
                    enQueue(q, item);
                    break;

            case 2 : ele = deQueue(q);
                    break;

            case 3 : printf("\nThe elements of the queue are:\n");
                    display(q);
                     break;
                     
            default : exit(0);
        }
    }
}
