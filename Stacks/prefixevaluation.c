/* Program to evaluate the given prefix expression */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct stackstruct
{
    int expstack[50];
    int top;
}s;

void push(int a)
{
    if(s.top >= 49)
    {
        printf("\nStack Overflow\n");
        return;
    }
    s.expstack[++s.top] = a;
}

int pop()
{
    if(s.top == -1)
    {
        printf("\nStack Empty\n");
        return 0;
    }
    int ele;
    ele = s.expstack[s.top--];
    return ele;
}

int calculate(char symbol, int x, int y)
{
    int res;
    switch (symbol)
    {
    case '+': res = x+y; 
            break;
    
    case '-': res = x-y;
            break;

    case '*': res = x*y;
            break;

    case '/': if(y==0)
            {
                printf("\nInvalid expression\n");
                return 0;
            }
            res = x/y;
            break;

    case '$':
    case '^': res = pow(x, y);
            break;
    
    default: res = 0;
        break;
    }
    return res;
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
        printf("%c\t", *(s.expstack+i));
    }
    return;
}

void main()
{
    int i; 
    int res, x, y;
    char pre[50];
    printf("\nEnter the prefix expression\n");
    scanf("%s", pre);
    strrev(pre);
    for(i=0; i<strlen(pre); i++)
    {
        display();
        if(isdigit(pre[i]))
        {
            push((pre[i] - '0'));
        }
        else
        {
            x = pop();
            y = pop();
            res = calculate(pre[i], x, y);
            push(res);
        }
    }
    res = pop();
    printf("\nThe value of the expression is %d\n", res);
}
