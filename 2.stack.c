#include <stdio.h>
#define MAX 10
int arr[MAX];
int top = 0;
void push(int x);
void pop();
void display();
int x ,popped_value;
void main()
{
    int choice;
    do{
        printf("------MENU------\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice>5||choice<1)
            printf("Invalid choice");
        else
        {
            switch(choice)
            {
                case 1:
                    push(x);
                    break;

                case 2:
                    pop();
                    break;

                case 3:
                    display();
                    break;

                case 4:
                    ("EXITING THE PROGRAM");
                    break;
            }
          }
    }while(choice!=4);
}

void push(x)
{
    if(top>MAX)
    {

        printf("Stack Overflow");
    }
    else
    {
        printf("Enter the element to be pushed: ");
        scanf("%d",&x);
        arr[top]=x;
        top++;

    }
}

void pop()
{
    if(top<0)
    {
        printf("Stack Underflow");
    }
    else{
        top--;
        int popped_value = arr[top];
        printf("The popped element is %d",popped_value);

    }
}

void display()
{
    int i;
    if(top<0)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Printing the stack element....\n");
        for(i=0;i<top;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
