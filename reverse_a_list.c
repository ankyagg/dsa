#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = 0;

void push(char c)
{
    if(top>=MAX)
    {
        printf("Stack Overflow");
        exit(1);
    }
    else{
        stack[top]=c;
        top++;
    }
}

char pop()
{
    if(top<0)
    {
        printf("UNDERFLOW");
        exit(1);
    }
    else
    {   top--;
        return stack[top];
    }
}

void reverselist(char *list,int size)
{
    for(int i=0;i<size;i++)
    {
        push(list[i]);
    }
    for(int i=0;i<size;i++)
    {
        list[i]=pop();
    }
}

int main()
{
    char list[MAX];
    int size,i;
    printf("Enter the size of your list:");
    scanf("%d",&size);

    printf("Enter the charachter's: ");
    for(i=0;i<size;i++)
    {
         scanf(" %c",&list[i]);
    }
    reverselist(list,size);

    printf("Reversed list:");
    for(i=0;i<size;i++)
    {
        printf("%c ",list[i]);
    }
    return 0;
}
