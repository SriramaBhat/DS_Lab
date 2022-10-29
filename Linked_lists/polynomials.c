/* Program to add two polynomials and give their sum */
#include<stdio.h>
#include<stdlib.h>

struct polynode
{
    int coeff, exponent;
    struct polynode *link;
};

typedef struct polynode * NODE;

NODE create()
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct polynode));
    if(newnode == NULL)
    {
        printf("\nMemory Error\n");
        return NULL;
    }
    newnode->link = NULL;
    return newnode;
}

NODE insert(NODE start, int co, int exp)
{
    NODE temp, cur;
    temp = create();
    temp->coeff = co;
    temp->exponent = exp;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        cur = start;
        while(cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = temp;
    }
    return start;
}

NODE addPoly(NODE P1, NODE P2, NODE P3)
{
    NODE temp1, temp2, temp3, prev;
    temp1 = P1;
    temp2 = P2;
    temp3 = P3;
    prev = NULL;
    if(P1 == NULL && P2 == NULL)
    {
        return NULL;
    }
    else if(P1 != NULL && P2 == NULL)
    {
        return P1;
    }
    else if(P1 == NULL && P2 != NULL)
    {
        return P2;
    }
    else
    {
        while(temp1 != NULL && temp2 != NULL)
        {
            if(P3 == NULL)
            {
                P3 = create();
                temp3 = P3;
                prev = P3;
            }
            else
            {
                temp3 = NULL;
                temp3 = create();
                prev->link = temp3;
                prev = prev->link;
            }

            if(temp1->exponent > temp2->exponent)
            {
                temp3->coeff = temp1->coeff;
                temp3->exponent = temp1->exponent;
                temp1 = temp1->link;
            }
            else if(temp1->exponent < temp2->exponent)
            {
                temp3->coeff = temp2->coeff;
                temp3->exponent = temp2->exponent;
                temp2 = temp2->link;
            }
            else if(temp1->exponent == temp2->exponent)
            {
                temp3->coeff = temp1->coeff + temp2->coeff;
                temp3->exponent = temp1->exponent + temp2->exponent;
                temp1 = temp1->link;
                temp2 = temp2->link;
            }
        }

        while(temp1 != NULL)
        {
            temp3 = create();
            temp3->coeff = temp1->coeff;
            temp3->exponent = temp1->exponent;
            prev->link = temp3;
            prev = prev->link;   
        }
        
        while(temp2 != NULL)
        {
            temp3 = create();
            temp3->coeff = temp2->coeff;
            temp3->exponent = temp2->exponent;
            prev->link = temp3;
            prev = prev->link;   
        }
        
    }

    return P3;

}

void display(NODE start)
{
    NODE temp = start;
    while(temp->link != NULL)
    {
        printf("%d x^%d + ", temp->coeff, temp->exponent);
        temp = temp->link;
    }
    printf("%d x^%d + ", temp->coeff, temp->exponent);
    printf("\n");
}

void main()
{
    NODE P1, P2, P3;
    P1 = P2 = P3 = NULL;
    int choice, co, exp;
    for(;;)
    {
        printf("\n1)Add to P1\n2)Add to P2\n3)Add the polynomials\n4)Display\n5)Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nEnter the coefficient:\n");
                   scanf("%d", &co);
                   printf("\nEnter the exponent:\n");
                   scanf("%d", &exp);
                   P1 = insert(P1, co, exp);
                   break;

            case 2: printf("\nEnter the coefficient:\n");
                   scanf("%d", &co);
                   printf("\nEnter the exponent:\n");
                   scanf("%d", &exp);
                   P2 = insert(P2, co, exp);
                   break;

            case 3: P3 = addPoly(P1, P2, P3);
                   break;

            case 4: printf("\nP1:\n");
                   display(P1);
                   printf("\nP2:\n");
                   display(P2);
                   printf("\nSum:\n");
                   display(P3);
                   break;

            default: exit(0);
        }
    }
}