void delete_right()
{
    if (left == -1)
        printf("OVERFLOW\n");
    printf("Deleted element",deque[right]);

    if (left == right)
        left= -1,right=-1;
    else
    {
        if(right=0)
            right = MAX-1;
        else
            right = right -1;
    }
}
