#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node* next;
};
struct node* front = NULL;

void enqueue(int priority , int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->priority = priority;
    newnode->next = NULL;

    if(front==NULL || front->priority > priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else{
        struct node* temp = front;
        while(temp->next!=NULL && temp->next->priority<=priority)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("QUEUE EMPTY");
    }
    else{
        struct node* temp = front;
        front= front->next;
        free(temp);
    }
}

void display()
{
    if(front==NULL)
    {
        printf("QUEUE EMPTY");
    }

    else
    {
        struct node* temp = front;
        while(temp!=NULL)
        {
            printf("%d(priority:%d)->",temp->data,temp->priority);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, value, priority;
    do
    {
        printf("\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d",&value);
            printf("Enter the priority: ");
            scanf("%d",&priority);
            enqueue(priority,value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        }
    }while(choice!=4);
    return 0;
}
