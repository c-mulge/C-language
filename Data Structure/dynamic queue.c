//Implementation of Dynamic Queue

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct node *getnode(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=value;
    temp->next=NULL;
    return temp;
}

void initq(struct queue *q)
{
    q->front=NULL;
    q->rear=NULL;
}

void freenode(struct node *p)
{
    free(p);
}

int isempty(struct queue *q)
{
    return(q->rear==NULL && q->front==NULL)?1:0;
}

void addq(struct queue *q,int value)
{
    struct node *temp=getnode(value);
    if(q->rear==NULL)
    {
        q->rear=temp;
        q->front=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}

int deleq(struct queue *q)
{
    struct node *temp=NULL;
    int value;
    if(isempty(q))
    {
        printf("Queue Underflow!");
        exit(1);
    }
    value=q->front->info;
    temp=q->front;
    q->front=temp->next;

    if(q->rear==temp)
    {
        q->rear=NULL;
    }
    freenode(temp);
    return value;
}

void display(struct queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    struct node *p = q->front;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
}


int main()
{
    struct queue q;
    initq(&q);
    int choice,temp;
    while(1)
    {
        printf("\nQueue Operations: \n");
        printf("1. Add in queue\n");
        printf("2. Delete in queue\n");
        printf("3. Front in queue\n");
        printf("4. Rear in queue\n");
        printf("5. Display queue\n");
        printf("6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter elements to add: ");
                scanf("%d",&temp);
                addq(&q,temp);
                break;
            case 2:
                printf("Deleted element: %d\n",deleq(&q));
                break;
            case 3:
                if(isempty(&q))
                {
                    printf("Queue is empty");
                    exit(0);
                }
                printf("Front of queue is %d\n",(q.front)->info);
                break;
            case 4:
                if(isempty(&q))
                {
                    printf("Queue is empty");
                    exit(0);
                }
                printf("Rear of queue is %d\n",(q.rear)->info);
                break;
            case 5:
                printf("Queue elements are: ");
                display(&q);
                printf("\n");
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

// int main()
// {
//     struct queue q;
//     initq(&q);
//     addq(&q,10);
//     addq(&q,20);
//     addq(&q,30);
//     display(&q);
// }
