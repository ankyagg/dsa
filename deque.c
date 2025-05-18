#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next
};
struct node* front=NULL;
struct node* rear=NULL;

void enqueuefront(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = front;
    front = newnode;

    if(rear==NULL)
    {
        front=rear=newnode
    }
    printf("%d is enqueued at the front",front->data);
}

void enqueueEnd(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(rear==NULL)
    {
        front=rear=newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    printf("The value %d is been enqueued at the end of queue",rear->data)
}

void dequeuefront()
{
    struct node* temp;

    if(front==NULL)
    {
        printf("QUEUE UNDERFLOW");
    }
    if(front==rear)
    {
        free(front);
        front = rear = NULL;
        return;
    }
    temp = front;
    front = front->next;
    printf("The deleted element is %d",temp->data);
    free(temp);
}

void dequeueend()
{
    struct node* temp;

    if(front==NULL)
    {
        printf("QUEUE IS EMPTY");
        return;
    }
    if(front==rear)
    {
        free(front);
        front = rear = NULL;
        return;
    }
    temp=front;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next =NULL;
    rear = temp;
}

void display()
{
    struct node* temp=front;

    if(front==NULL)
    {
        printf("QUEUE IS EMPTY");
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    print("\n");
}

int main () {
    int choice,val;
    do {
        printf("\nSelect ANY one:\n");
        printf("1.Enqueue at Front\n2.Enqueue at Rear\n3.Dequeue at Front\n4.Dequeue at Rear\n5.Display\n6.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d",&val);
            enqueuefront(val);
            break;

        case 2:
            printf("Enter the value to be enqueued");
            scanf("%d",&val);
            enqueueEnd(val);
            break;

        case 3:
            dequeueend();
            break;

        case 4:
            dequeuefront();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);
        }while(choice!=6);

    }
