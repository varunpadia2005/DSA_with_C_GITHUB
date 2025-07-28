int main()
{
    cqueue* s=NULL;
    int size,ch,data;
    printf("Enter the size of the cqueue: ");
    scanf("%d",&size);
    insertcqueue(&s,size);
    do
    {
        printf("0. Exit\n1. Enqueue\n2. Dequeue\n3. Print\n");
        printf("Enter the choice of the cqueue function: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Thanks for using the Circular Queue operations");
                    break;
            case 1: printf("Enter the data to be pushed: ");
                    scanf("%d",&data);
                    encqueue(s,data);
                    printf("Data enqueued\n");
                    break;
            case 2: printf("%d Dequeued\n",decqueue(s));
                    break;
            case 3: printf("Circular Queue Data : ");
                    printcqueue(s);
                    break;
            default:printf("Invalid Input");
        }
    }while(ch!=0);
    return 0;
}