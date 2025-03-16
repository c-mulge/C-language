//Static Queue

#include <stdio.h>
#include <stdlib.h>
#define maxsz 20

struct queue{
    int data[maxsz];
    int front,rear;
};

int isempty(struct queue *q)
{
    return q->rear==q->front;
}

int isfull(struct queue *q)
{
    return q->rear==q->front;
}

void initq(struct queue *q)
{
    q->rear=maxsz-1;
    q->front=maxsz-1;
}

void addq(struct queue *q,int value)
{
   if(q->rear==maxsz-1)
   {
    q->rear=0;
   }
   else{
    q->rear++;
   }
   if(isfull(q))
   {
        printf("Queue is full");
        exit(1);
   }
   q->data[q->rear]=value;
}

int deleq(struct queue *q)
{
    if(isempty(q))
    {
        printf("Queue is empty");
        exit(1);
    }
    if(q->front==maxsz-1)
    {
        q->front=0;
    }
    else
    {
        q->front++;
    }
    return q->data[q->front];
}

void display(struct queue *q)
{
    int i=q->front;
    if(isempty(q))
    {
        printf("Queue is empty");
        exit(1);
    }
    while(i!=q->rear)
    {
        if(i==maxsz-1)
        {
            i=0;
        }
        else{
            i++;
        }
        printf("%d ",q->data[i]);
    }
}

int main()
{
    struct queue q;
    int choice,num;
    initq(&q);

    while(1)
    {
        printf("\nOperations are: ");
        printf("\n 1.Add in queue");
        printf("\n 2.Remove from queue");
        printf("\n 3.Front of queue");
        printf("\n 4.Rear of queue");
        printf("\n 5.Display queue");
        printf("\n 6.Exit");
        printf("\nEnter your choice: ");
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
                    printf("It is empty");
                    exit(1);
                }
                if(q.front==maxsz-1)
                {
                    printf("Front of Queue is %d",(q.data[0]));
                    break;
                }
                printf("Front of Queue is %d",(q.data[q.front+1]));
                break;
            case 4:
                if(isempty(&q))
                {
                    printf("It is empty");
                    exit(1);
                }
                if(q.rear==maxsz-1)
                {
                    printf("Front of Queue is %d",(q.data[0]));
                    break;
                }
                printf("Front of Queue is %d",(q.data[q.rear]));
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