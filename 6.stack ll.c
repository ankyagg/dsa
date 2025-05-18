#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;
int x;
void push(x)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value to be pushed: ");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=top;
    top=newnode;
    printf("The value %d has been pushed\n",x);
}

void pop()
{
    if(top==NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else
    {
        struct Node *temp = top;
        printf("The deleted element is %d\n",top->data);
        top=top->next;
        free(temp);
    }
}

void display()
{
    if(top==NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct Node *temp = top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    int choice;

    do{
        printf("---MENU---\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
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
            printf("EXITING THE PROGRAM");
        }
    }while(choice!=4);
}
