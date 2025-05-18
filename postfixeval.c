#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top=0;

void push(int x)
{
    if(top>=MAX)
    {
        printf("Stack Overflow\n");
        return;
    }
    else{
        stack[top++]=x;
    }
}

int pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
    }
    else{
        return stack[--top];
    }
}

int evalPostfix(char postfix[])
{
    int i = 0;
    while(postfix[i]!='\0')
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            int op2=pop();
            int op1=pop();
            switch(postfix[i])
            {
                case'+':push(op1+op2); break;
                case'-':push(op1-op2); break;
                case'*':push(op1*op2); break;
                case'/':push(op1/op2); break;
            }
        }
        i++;
    }
    return pop();
}

int main()
{
    char postfix[100];

    printf("Enter the postfix expression: ");
    scanf("%s",postfix);

    int result = evalPostfix(postfix);
    printf("%d",result);

    return 0;
}
