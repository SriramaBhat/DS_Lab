/* Program to check if the given string is a palindrome or not */ 
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    char *reversestr;
    int top;
}rstack;

void push(char a)
{
    rstack.top++;
    *(rstack.reversestr+rstack.top) = a;
}

char pop()
{
    char ele;
    ele = *(rstack.reversestr+rstack.top);
    rstack.top--;
    return ele;
}

void main()
{
    rstack.top = -1;
    char string[100];
    int i;
    printf("\nEnter the string to be checked\n");
    fgets(string, 100, stdin);
    int len = strlen(string);
    rstack.reversestr = (char *)malloc(len*sizeof(char));
    for (i = 0; i < len; i++)
    {
        push(string[i]);
    }
    int count = 0;
    for(i=0; i<len; i++)
    {
        if(string[i] == pop())
        {
            count++;
        }
    }
    if(count == len)
    {
        printf("\nThe string is a palindrome\n");  
    }
    else
    {
        printf("\nThe string is not a palindrome\n");
    }
    
}
*/

#include <stdio.h>
#include <string.h>
void push(char);
char pop();
char stack[100];
int top = -1;
void main()
{
char str[100];
int i, count = 0, len;
printf("Enter string to check it is palindrome or not : ");
scanf("%s", str);
len = strlen(str);
for (i = 0; i < len; i++)
{
push(str[i]);
}
for (i = 0; i < len; i++)
{
if (str[i] == pop())
count++;
}
if (count == len)
printf("%s is a Palindrome string\n", str);
else
printf("%s is not a palindrome string\n", str);
}
/* Function to push character into stack */
void push(char c)
{
stack[++top] = c;
}
/* Function to pop the top character from stack */
char pop()
{
return(stack[top--]);
}