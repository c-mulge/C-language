//Dynamic Queue

#include <stdio.h>
#include <stdlib.h>

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

int isempty(struct queue *q)
{
    return(q->rear==NULL && q->front==NULL);
}

void freenode(struct node *p)
{
    free(p);
}

void initq(struct queue *q)
{
    q->rear=NULL;
    q->front=NULL;
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
    if(isempty(q))
    {
        printf("empty queue\n");
        exit(1);
    }
    int value;
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
    if(isempty(q))
    {
        printf("Empty queue\n");
        exit(1);
    }
    struct node *p=q->front;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}

int main()
{
    struct queue q;
    initq(&q);
    int num,choice;

    while(1)
    {
        printf("\n Operations are: ");
        printf("\n 1. Add in queue");
        printf("\n 2. Remove from queue");
        printf("\n 3. Front of queue");
        printf("\n 4. Rear of queue");
        printf("\n 5. Display queue");
        printf("\n 6. Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the number: ");
                scanf("%d",&num);
                addq(&q,num);
                break;
            case 2:
                printf("Removed: %d",deleq(&q));
                break;
            case 3:
                if(isempty(&q))
                {
                    printf("Empty");
                    exit(0);
                }
                printf("Front of queue is %d",(q.front)->info);
                break;
            case 4:
                if(isempty(&q))
                {
                    printf("Empty");
                    exit(0);
                }
                printf("Rear of queue is %d",(q.rear)->info);
                break;
            case 5:
                printf("Queue: ");
                display(&q);
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Invalid choice");
        }
    } return 0;
}