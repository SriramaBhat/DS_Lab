/* Program to demonstrate operations on a circular queue using dynamic memory allocation */
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int count = 0;

struct dyncircularqueue
{
    int *queue;
    int front, rear, size;
};

typedef struct dyncircularqueue CQ;

void enQueue(CQ *q, int item)
{
    if((q->front==0 && q->rear == (MAX-1)) || (q->front == (q->rear+1)%MAX))
    {
        printf("\nQueue Overflow\n");
        return;
    }
    else
    {
        q->rear = (q->rear+1)%MAX;
        q->size++;
        q->queue = (int *)realloc(q->queue, q->size*sizeof(int));        
        *(q->queue+q->rear) = item;
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
    if((q->front == -1) || (q->front == (((q->rear+1)%MAX)-1)))
    {
        printf("\nQueue empty\n");
        return;
    }
    else if (q->front == q->rear)
    {
        printf("\nDeleted item is %d\n", *(q->queue+q->front));
        q->size--;
        q->queue = NULL;
        count--;
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        int item;
        item = *(q->queue+q->front);
        q->front = (q->front+1)%MAX;
        q->size--;
        q->queue = (int *)realloc(q->queue, q->size*sizeof(int));
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
        j = (j+1)%MAX;
    }
    return;
}

void main()
{
    int item, ele, choice;
    CQ *q;
    q->queue = NULL;
    q->size = 0;
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