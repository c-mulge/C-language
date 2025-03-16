//Circular Array - Queue Implementation

#include<stdio.h>
#include<stdlib.h>
#define maxsz 10

struct queue
{
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
        printf("Queue overflow!");
        exit(1);
    }
    q->data[q->rear]=value;
}

int deleq(struct queue *q)
{
    if(isempty(q))
    {
        printf("Queue underflow!");
        exit(1);
    }
    if(q->front==maxsz-1)
    {
        q->front=0;
    }
    else{
        q->front++;
    }
    

    return q->data[q->front];
}

// void display(struct queue * q)
// {
//     int i=0;
//     while(i <=q->rear)
//     {
//         printf("%d ",q->data[i]);
//         i++;
//     }
// }

// int main() 
// {
//     struct queue q;
//     initq(&q);
//     int num,value;
//     int n,choice;
//     while(1)
//     {
//         printf("\nQueue Operations: \n");
//         printf("1. Add elements in queue\n");
//         printf("2. Delete elements in queue\n");
//         printf("3. Display queue\n");
//         printf("4. Exit");
//         printf("\nEnter your choice: ");
//         scanf("%d",&choice);
//         switch(choice)
//         {
//             case 1:
//                 printf("Enter the number of elements to enqueue: ");
//                 scanf("%d", &n);
//                 if (n <= 0 || n > maxsz) 
//                 {
//                     printf("Invalid number of elements.\n");
//                     return 1;
//                 }
//                 printf("Enter the elements to add to the queue:\n");
//                 for (int i = 0; i < n; i++) 
//                 {
//                     scanf("%d", &num);
//                     addq(&q, num);
//                 }
//                 printf("Queue is: ");
//                 display(&q);
//                 break;
//             case 2:
//                 if (isempty(&q))
//                 {
//                     printf("Queue is empty.\n");
//                 }
//                 else
//                 {
//                     value = deleq(&q);
//                     printf("Dequeued: %d\n", value);
//                 }
//                 break;
//             case 3:
//                 printf("Queue is: ");
//                 display(&q);
//                 break;
//             case 4:
//                 exit(0);
//             default:
//                 printf("Invalid choice. Please enter a valid option.\n");
//         }
//     }
//     return 0;
// }

void display(struct queue *q)
{
    int i=q->front;
    if(isempty(q))
    {
        printf("Queue Underflow");
        exit(1);
    }
    while(i!=q->rear)
    {
        if(i==maxsz-1)
        {
            i=0;
        }
        else
        {
            i++;
        }
        printf("%d ",q->data[i]);
    }
}

// int main() 
// {
//     struct queue q;
//     initq(&q);
//     int num,value;
//     int n;
//     printf("Enter the number of elements to enqueue: ");
//     scanf("%d", &n);
//     if (n <= 0 || n > maxsz) 
//     {
//         printf("Invalid number of elements.\n");
//         return 1;
//     }
//     printf("Enter the elements to add to the queue:\n");
//     for (int i = 0; i < n; i++) 
//     {
//         scanf("%d", &num);
//         addq(&q, num);
//     }
//     display(&q);
//     // printf("\nDequeuing elements from the queue:\n");
//     // while (!isempty(&q)) 
//     //{
//         value = deleq(&q);
//         printf("Dequeued: %d\n", value);
//         display(&q);
//         //the queue will be not fully empty as there is atleast one element is present.
//     //}
//     return 0;
// }

int main()
{
    struct queue q;
    initq(&q);
    int num;
    int choice;
    while(1)
    {
        printf("\nOperatios of Queue: ");
        printf("\n1. Add in Queue");
        printf("\n2. Delete in Queue");
        printf("\n3. Front in Queue");
        printf("\n4. Rear in Queue");
        printf("\n5. Display Queue");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the elements to add in queue: \n");
                scanf("%d",&num);
                addq(&q,num);
                break;
            case 2:
                printf("Delete: %d\n",deleq(&q));
                break;
            case 3:
                if(isempty(&q))
                {
                    printf("Queue is empty");
                    exit(0);
                }
                if(q.front==maxsz-1)
                {
                    printf("Front of Queue is %d\n",(q.data[0]));
                    break;
                }
                printf("Front of queue is %d\n",(q.data[q.front+1]));
                break;
            case 4:
                if(isempty(&q))
                {
                    printf("Queue is empty");
                    exit(0);
                }
                if(q.rear==maxsz-1)
                {
                    printf("Rear of Queue is %d\n",(q.data[0]));
                    break;
                }
                printf("Rear of queue is %d\n",(q.data[q.rear]));
                break;
            case 5:
                printf("Queue is: ");
                display(&q);
                printf("\n");
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Invalid choice");
                break;
        }

    }
    return 0;
}
