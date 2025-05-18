#include <stdio.h>
#define MAX 10
int left = -1;
int right = -1;

int main()
int choice;
printf("------MAIN MENU------");
printf("1.Input restricted queue");
printf("2.Output restricted queue");
scanf("%d",&choice);
switch(choice)
{
    case 1:
        input_queue();
        break;

    case 2:
        output_queue();
        break;
}

void inputr_queue()
{
int Ichoice;
do {
    printf("INPUT RESTRICTED DEQUE");
    printf("1.Insert at right");
    printf("2.Delete at right");
    printf("3.Delete at left");
    printf("4.Display");
    printf("5.Quit");
    printf("Enter your choice: ");
    scanf("%d",&Ichoice);
    switch (Ichoice)
    {
        case 1:
            insert_right();
            break;

        case 2:
            delete_right();
            break;

        case 3:
            delete_left();
            break;

        case 4:
            display();
            break;
    }
}while(Ichoice!=5);
}

void outputr_queue()
{
    int Xchoice;
    do {
        printf("INPUT RESTRICTED DEQUE");
        printf("1.Insert at right");
        printf("2.Insert at left");
        printf("3.Delete at right");
        printf("4.Display");
        printf("5.Quit");
        printf("Enter your choice: ");
        scanf("%d",&Xchoice);
        switch (Xchoice)
        {
            case 1:
                insert_right();
                break;

            case 2:
                insert_left();
                break;

            case 3:
                delete_right();
                break;

            case 4:
                display();
                break;
    }
}while(Xchoice!=5);
}

void insert_right()
{
    if(left==0 && right==MAX-1) || (left==right+1 )
}
