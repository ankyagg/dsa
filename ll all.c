    #include <stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* createnode(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
};

void insertatBEG(int value)
{
    struct node* newnode = createnode(value);
    newnode->next = head;
    head=newnode;
}

void insertatEND(int value)
{
    struct node* newnode = createnode(value);
    struct node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newnode;

}

void insertafterElement(int key,int value)
{
    struct node* temp = head;
    while(temp!=NULL && temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Value not found");
    }
    else{
        struct node* newnode = createnode(value);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insertafterPos(int pos,int value)
{
    if(pos==1)
    {
        struct node* newnode = createnode(value);
        newnode->next = head;
        head = newnode;
    }

    else
    {
        struct node* temp = head;
        for(int i=0; i< pos-1 && temp!=NULL;i++)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("Position off bound");
        }
        else
        {
            struct node* newnode = createnode(value);
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void deletefromBEG()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

void deletefromEND()
{
    if(head==NULL)
    {
        printf("Empty list");
    }
    if(head->next==NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    else
    {
        struct node* temp = head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void deleteafterelement(int key)
{
    struct node* temp = head;

    while(temp->data!=key && temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp==NULL || temp->next== NULL)
    {
        printf("Cant delete the element");
    }
    else
    {
        struct node* todelete = temp->next;
        temp->next = temp->next->next;
        free(todelete);
    }
}

void display()
{
    struct node* temp = head;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else{
        printf("List: ");
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void search(int key)
{
    struct node* temp = head;

    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("Entered element %d is found.\n",key);
        }
        temp=temp->next;
    }
    printf("Element not found");
}

void countNodes()
{
    struct node* temp = head;
    int count = 0;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Total no. of nodes present are %d",count);
}

int main()
{
    int choice, value,key,pos;

    do{
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert after an Element\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete after an Element\n");
        printf("8. Display List\n");
        printf("9. Search for an Element\n");
        printf("10. Count Nodes\n");
        printf("11. Reverse Traversal\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter the no. to be pushed: ");
            scanf("%d",&value);
            insertatBEG(value);
            break;

        case 2:
            printf("Enter the no. to be pushed: ");
            scanf("%d",&value);
            insertatEND(value);
            break;

        case 3:
            printf("Enter the no. to be pushed: ");
            scanf("%d",&value);
            printf("Enter the element after which we need to push: ");
            scanf("%d",&key);
            insertafterElement(key,value);
            break;

        case 4:
            printf("Enter the no. to be pushed: ");
            scanf("%d",&value);
            printf("Enter the position at which we need to push: ");
            scanf("%d",&pos);
            break;
        case 5:
            deletefromBEG();
            break;

        case 6:
            deletefromEND();
            break;

        case 7:
            printf("Enter the element after which you want to delete:");
            scanf("%d",&key);
            deleteafterelement(key);
            break;

        case 8:
            display();
            break;

        case 9:
            printf("Enter element to search: ");
            scanf("%d", &key);
            search(key);
            break;

        case 10:
            countNodes();
            break;
        case 11:
            printf("EXIITNG");
        }
    }while(choice!=11);
    return 0;
}
