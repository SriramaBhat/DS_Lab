/* Program to input, display, update and add time */
#include<stdio.h>
#include<stdlib.h>

struct time 
{
    int hours;
    int mins;
    int secs;
};

typedef struct time TI;

void read(TI *t)
{
    printf("\nPlease enter the time in the format hours:minutes:seconds\n");
    scanf("%d:%d:%d", &t->hours, &t->mins, &t->secs);
    return;
}

void display(TI t)
{
    printf("\nThe Time is\n");
    printf("%d:%d:%d", t.hours, t.mins, t.secs);
    return;
}

void update(TI *t)
{
    t->secs++;
    if(t->secs == 60)
    {
        t->secs = 0;
        t->mins++;
    }

    if(t->mins == 60)
    {
        t->hours++;
        t->mins = 0;
    }

    if(t->hours == 24)
    {
        t->hours = t->mins = t->secs = 0;
    }

    display(*t);
}

void add(TI *t1, TI *t2)
{
    TI t3;
    t3.hours = t3.mins = t3.secs = 0;
    read(t1);
    read(t2);
    t3.secs = t1->secs + t2->secs;
    if(t3.secs > 59)
    {
        t3.mins++;
        t3.secs = t3.secs - 60;
    }

    t3.mins = t3.mins + t1->mins + t2->mins;
    if(t3.mins > 59)
    {
        t3.hours++;
        t3.mins = t3.mins - 60;
    }

    t3.hours = t3.hours + t1->hours + t2->hours;
    if(t3.hours == 24)
    {
        t3.hours = t3.mins = t3.secs =0;
    }

    display(t3);
    return;
}

void main()
{
    TI *t1, *t2;
    t1 = t2 = NULL;
    int choice;
    for(;;)
    {
        printf("\nThe following operations can be carried out\n");
        printf("\n1)Reading the time\n2)Displaying the time\n3)Updating the time by one second\n4)Adding two times\n5)Exit\n");
        printf("Please enter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: read(t1);
                    break;

            case 2: display(*t1);
                    break;

            case 3: update(t1);
                    break;

            case 4: add(t1, t2);
                    break;

            default: exit(0);  
        }
    }
    
}