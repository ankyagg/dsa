#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  // You can change the size of the queue here

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x)
{
    if((rear+1) % MAX == front)
    {
        printf("Queue is full");
    }
    if(front == -1 && rear == -1)
    {
        rear = 0;
        front = 0;
        queue[rear]=x;
    }
    else{
        rear = (rear+1)%MAX;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==rear==-1)
    {
        printf("Empty list");
    }
    else if(front==rear)
    {
        printf("Dequeued element is %d",queue[rear]);
        front = -1;
        rear = -1;
    }
    else{
        printf("Dequeued element is %d",queue[front]);
        front = (front+1)%MAX;
    }
}

void display()
{
    if(front=-1)
    {
        printf("Queue empty");
    }
    else
    {
        printf("Printing element");
        for(i=front;i!=(rear+1)%MAX;i=(i+1)%MAX)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Using Array ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
