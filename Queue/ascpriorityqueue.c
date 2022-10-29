/* Program to demonstrate the operations on an ascending priority queue */
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int count = 0;

struct ascpriorityqueue
{
    int queue[CAPACITY];
    int front, rear;
};

typedef struct ascpriorityqueue APQ;

void enQueue(APQ *q, int item)
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

void deQueue(APQ *q)
{
    if((q->front > q->rear) || (q->front == -1))
    {
        printf("\nQueue Empty\n");
        return;
    }
    else
    {
        int i, small, pos;
        small = q->queue[q->front];
        pos = q->front;
        for(i=(q->front+1); i<=q->rear; i++)
        {
            if(small > q->queue[i])
            {
                small = q->queue[i];
                pos = i;
            }
        }
        for(i=pos; i<=q->rear; i++)
        {
            q->queue[i] = q->queue[(i+1)]; 
        }
        q->rear--;
        printf("\nThe element deleted is %d\n", small);
        return;
    }
}

void display(APQ *q)
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
    int item, small, choice;
    APQ *q;
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

            case 3 : printf("\nThe elements of the queue are:\n");
                    display(q);
                     break;
                     
            default : exit(0);
        }
    }
}