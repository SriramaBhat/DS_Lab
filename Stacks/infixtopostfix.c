/* Program to convert an infix expression to a postfix expression */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct stackstruct
{
    char *expstack;
    int top;
    int size;
}s;

void push(char a)
{
    s.top++;
    s.size++;
    s.expstack = realloc(s.expstack, s.size*sizeof(char));
    *(s.expstack+s.top) = a;
}

char pop()
{
    char ele;
    if(s.top == -1)
    {
        printf("\nStack Empty\n");
        return ele;
    }
    ele = *(s.expstack+s.top);
    s.top--;
    s.size--;
    s.expstack = realloc(s.expstack, s.size*sizeof(char)); 
    return ele;
}

int precedence(char a)
{
    if(a == '(' || a == '#')
        return 1;
    else if(a == '+' || a == '-')
        return 2;
    else if(a == '*' || a == '/')
        return 3;
    else if(a == '^' || a == '$')
        return 4;
}

/*void display()
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
} Not needed */

void main()
{
    s.top = -1;
    s.size = 0;
    char in[50], post[50], junk;
    printf("\nEnter the infix expression\n");
    scanf("%s", in);
    s.expstack = NULL;
    int i, j=0;
    push('#');
    for(i=0; i<strlen(in); i++)
    {
        if(in[i] == '(')
        {
            push(in[i]);
        }
        else if(isalnum(in[i]))
        {
            post[j++] = in[i];
        }
        else if(in[i] == ')')
        {
            while(*(s.expstack+s.top) != '(')
                post[j++] = pop();
            junk = pop();
        }
        else if(precedence(*(s.expstack+s.top)) < precedence(in[i]))
        {
            push(in[i]);
        }
        else
        {
            while(precedence(*(s.expstack+s.top)) >= precedence(in[i]))
            {
                post[j++] = pop();
            }
            push(in[i]);   
        }
    }
    while(s.expstack[s.top] != '#')
    {
        post[j++] = pop();
    }
    post[j] = '\0';
    printf("%s", post); 
}