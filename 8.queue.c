#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = 0;
int rear = 0;
int x;
void enqueue(x);
void dequeue();
void display();

void main()
{
    int choice;
    do{
        printf("----MENU----\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("EXITING THE PROGRAM");

        }
    }while(choice!=4);
}

void enqueue(int x)
{
    if(rear==MAX)
    {
        printf("Queue Full!!");
    }
    else
    {
        printf("Enter the element to enqueue: ");
        scanf("%d",&x);
        queue[rear]=x;
        printf("The element %d is enqueued in the queue\n",queue[rear]);
        rear++;
    }
}

void dequeue()
{
    if(front == 0 && rear==0)
    {
        printf("Queue Empty!!");
    }
    else
    {
        int dequeued_el = queue[front];
        printf("The dequeued element is %d\n",queue[front]);
        front++;
    }
}

void display()
{
    if(front==0 && rear==0)
    {
        printf("Queue Empty!!");
    }
    else
    {
        printf("Printing the element....");
        for (int i=front;i<rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
