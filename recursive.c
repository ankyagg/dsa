#include<stdio.h>

void fibonacci(int n)
{
    int a=0,b=1,next,i;
    printf("Fibonacci series: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a);
        next = a+b;
        a=b;
        b=next;
    }
}

int factorial(int n)
{
    if(n==0 || n==1)
        return 1;

    else{
        return n*factorial(n-1);
    }
}
int main()
{
    int choice,n;
    do{
    printf("\n-------MENU-------\n");
    printf("1.Fibonacci Series\n2.Factorial\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Calculate the fibonacci equivalent: ");
        scanf("%d",&n);
        fibonacci(n);
        break;

    case 2:
        printf("Calculate the factorial: ");
        scanf("%d",&n);
        printf("%d",factorial(n));
        break;
    }
    }while(choice!=3);
}
