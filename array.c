#include <stdio.h>

int a[20], size;

void insert(int posn, int ele);
void deleteElement();
void display();

int main() // changed void main to int main
{
    int choice;
    printf("Enter size of array: ");
    scanf("%d", &size);
    if (size > 20)
        printf("\nOverflow");
    else
    {
        printf("\nEnter elements of array:\n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }
    }
    do
    {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoose your option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int posn, ele;
            printf("Enter the position of the element to be inserted: ");
            scanf("%d", &posn);
            printf("Enter the value of the element to be inserted: ");
            scanf("%d", &ele);
            insert(posn, ele);
            display();
            break;
        }
        case 2:
            deleteElement();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting the program...");
            break;
        default:
            printf("\nInvalid input");
        }
    } while (choice != 4);

    return 0; // since main is int
}

void insert(int posn, int ele)
{
    if (posn <= 0 || posn > size + 1)
    {
        printf("\nInvalid position");
        return;
    }
    if (size >= 20)
    {
        printf("\nArray is full (OVERFLOW)");
        return;
    }
    for (int i = size - 1; i >= posn - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[posn - 1] = ele;
    size++;
}

void deleteElement()
{
    int posn;
    printf("\nEnter the position of the element to be deleted: ");
    scanf("%d", &posn);
    if (posn <= 0 || posn > size)
    {
        printf("\nInvalid position");
    }
    else
    {
        int x = a[posn - 1];
        for (int i = posn - 1; i < size - 1; i++)
        {
            a[i] = a[i + 1];
        }
        size--;
        printf("\nThe deleted element is: %d", x);
    }
}

void display()
{
    if (size == 0)
    {
        printf("\nArray is empty.\n");
        return;
    }
    printf("\nElements of array are:\n");
    for (int i = 0; i < size; i++)
        printf("%d\n", a[i]);
}
