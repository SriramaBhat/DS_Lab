/* Program to evaluate the given postfix expression */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct stackstruct
{
    float expstack[50];
    int top;
}s;

void push(float a)
{
    if(s.top >= 49)
    {
        printf("\nStack Overflow\n");
        return;
    }
    s.expstack[++s.top] = a;
}

float pop()
{
    if(s.top == -1)
    {
        printf("\nStack Empty\n");
        return 0;
    }
    float ele;
    ele = s.expstack[s.top--];
    return ele;
}

float calculate(char symbol, float x, float y)
{
    float res;
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

void main()
{
    int i; 
    float res, x, y;
    char post[50];
    printf("\nEnter the postfix expression\n");
    scanf("%s", post);
    for(i=0; i<strlen(post); i++)
    {
        if(isdigit(post[i]))
        {
            push((post[i] - '0'));
        }
        else
        {
            y = pop();
            x = pop();
            res = calculate(post[i], x, y);
            push(res);
        }
    }
    res = pop();
    printf("\nThe value of the expression is %.2f\n", res);
}
