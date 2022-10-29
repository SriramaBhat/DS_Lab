/* Program to demonstrate the operations on a circular queue */
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int count = 0;

struct circularqueue
{
    int queue[CAPACITY];
    int front, rear;
};

typedef struct circularqueue CQ;

void enQueue(CQ *q, int item)
{
    if((q->front==0 && q->rear == (CAPACITY-1)) || (q->front == (q->rear+1)%CAPACITY))
    {
        printf("\nQueue Overflow\n");
        return;
    }
    else
    {
        q->rear = (q->rear+1)%CAPACITY;
        q->queue[q->rear] = item;
        if(q->front == -1)
        {
            q->front = 0;
        }
        count++;
        return;
    }
}

void deQueue(CQ *q)
{
    if((q->front == -1) || (q->front == (((q->rear+1)%CAPACITY)-1)))
    {
        printf("\nQueue empty\n");
        return;
    }
    else if (q->front == q->rear)
    {
        printf("\nDeleted item is %d\n", q->queue[q->front]);
        count--;
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        int item;
        item = q->queue[q->front];
        q->front = (q->front+1)%CAPACITY;
        count--;
        printf("\nDeleted item is %d\n", item);
        return;
    }
}

void display(CQ *q)
{
    if(q->front == -1)
    {
        printf("\nQueue empty\n");
        return;
    }
    int i, j;
    j = q->front;
    printf("\nThe elements of the queue are:\n");
    for(i=1; i<=count; i++)
    {
        printf("%d\t", q->queue[j]);
        j = (j+1)%CAPACITY;
    }
    return;
}

void main()
{
    int item, ele, choice;
    CQ *q;
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

            case 2 : deQueue(q);
                    break;

            case 3 : display(q);
                    break;
                     
            default : exit(0);
        }
    }
}