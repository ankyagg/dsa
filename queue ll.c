#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* front= NULL;
struct node* rear = NULL;

void enqueue(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data=x;
    newnode->next=NULL;

    if(rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear= newnode;
    }
    printf("%d enqueued to the queue.\n", x);
}

void dequeue()
{
    if (front == NULL) {
        printf("Queue UNDERFLOW (empty queue).\n");
        return;
    }

    struct node* temp = front;
    printf("The dequeued element is %d",temp->data);
    front = front->data;
    free(temp);
}

void display()
{
    struct node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int choice , x ;
    while (1) {
        printf("\n--- Queue Using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d",&x);
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("EXIT");
            break;
        }
}
return 0;
}
