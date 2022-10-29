/* Program to demonstrate operations on a double ended queue */
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

struct dequeue
{
    int queue[CAPACITY];
    int front, rear;
};

typedef struct dequeue DQ;

void insert_front(DQ *q, int item)
{
    if(q->front <= 0)
    {
        printf("\nElement cannot be inserted at the front\n");
        return;
    }
    else
    {
        q->queue[--q->front] = item;
        if(q->rear == -1)
        {
            q->rear = 0;
        }
        return;
    }
}

void insert_rear(DQ *q, int item)
{
    if(q->rear == (CAPACITY-1))
    {
        printf("\nElement cannot be inserted from the rear\n");
        return;
    }
    else
    {
        q->queue[++q->rear] = item;
/*        if(q->front == -1)
        {
            q->front = 0;
        } */
        return;
    }
}

void delete_front(DQ *q)
{
    if((q->front > q->rear) || (q->front == -1))
    {
        printf("\nThe element cannot be deleted from front\n");
        return;
    }
    else
    {
        int ele;
        ele = q->queue[q->front++];
        printf("\nThe element deleted is %d\n", ele);
        return;
    }
}

void delete_rear(DQ *q)
{
    if(q->rear == -1)
    {
        printf("\nElement cannot be deleted from rear\n");
        return;
    }
    else
    {
        int ele;
        ele = q->queue[q->rear--];
        printf("\nThe element deleted is %d\n", ele);
        return;
    }
}

void display(DQ *q)
{
    if((q->rear < q->front) || (q->front == -1))
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
    DQ *q;
    q->front = 0;
    q->rear = -1;
    for(;;)
    {
        printf("\n1)Insert front\n2)Insert rear\n3)Delete front\n4)Delete rear\n5)Display\n6)Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1 : printf("\nEnter the element to be inserted\n");
                    scanf("%d", &item);
                    insert_front(q, item);
                    break;

            case 2 : printf("\nEnter the element to be inserted\n");
                    scanf("%d", &item);
                    insert_rear(q, item);
                    break;

            case 3 : delete_front(q);
                    break;

            case 4 : delete_rear(q);
                    break;

            case 5 : printf("\nThe elements of the queue are:\n");
                    display(q);
                     break;
                     
            default : exit(0);
        }
    }
}