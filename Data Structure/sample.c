// // #include<stdio.h>
// // #include<stdlib.h>

// // struct node 
// // {
// //     int info;
// //     struct node *next;
// // };

// // struct node *getnode(int value)
// // {
// //     struct node *temp=NULL;
// //     temp=(struct node *)malloc(sizeof(struct node))
// //     temp->info=value;
// //     temp->next=NULL;
// //     return temp;
// // }

// // void freenode(struct node *p)
// // {
// //     free(p);
// // }

// // void initlist(struct node **head)
// // {
// //     (*head)=getnode(0);
// // }

// // void append(struct node *head,int value)
// // {
// //     struct node *p=head;
// //     struct node *temp=getnode(value);
// //     while(p->next)
// //     {
// //         p=p->next;
// //     }
// //     p->next=temp;
// //     head->info++;
// // }


// // void display(struct node *head)
// // {
// //     struct node *p=head->next;
// //     while(p)
// //     {
// //         printf("%d",p->info);
// //         p=p->next;
// //     }
// // }


// //Double circular Linked List

// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     struct node *prev;
//     int info;
//     struct node *next;
// };

// struct node *getnode(int value)
// {
//     struct node *temp=(struct node *)malloc(sizeof(struct node));
//     temp->prev=NULL;
//     temp->info=value;
//     temp->next=NULL;
//     return temp;
// }

// void freenode(struct node *p)
// {
//     free(p);
// }

// void initlist(struct node **head)
// {
//     (*head)=getnode(0);
//     (*head)->next=*head;
//     (*head)->prev=*head;
//     //(*head)->info=0;
// }

// void append(struct node *head, int value)
// {
//     struct node *temp = getnode(value);
//     struct node *p = head->prev;


//         // Update the pointers to make the new node the last node
//         temp->next=head;
//         temp->prev=p;
//         p->next = temp;
//         head->prev = temp;
//         head -> info++;
    
// }

// void display(struct node *head)
// {
//     struct node *p=head->next;
//     while(p!=head)
//     {
//         printf("%d ",p->info);
//         p=p->next;
//     }
// }

// void insert(struct node *h, int value, int pos)
// {
//     struct node *temp = getnode(value);
//     struct node *p = 0,*q=0;
//     int i;

//     if (pos >h->info)
//     {
//         printf("Invalid position.\n");
//         exit(1);
//     }

//     p=h->next;

//     for(i=1;i<pos;i++)
//     {
//         p=p->next;
//     }

//     temp=getnode(value);
//     q=p->prev;
//     temp->next=p;
//     temp->prev=q;
//     q->next=temp;
//     p->prev=temp;
//     h->info++;
    
// }

// void delete(struct node *h, int pos)
// {
//     struct node *p = h->next,*q=h;
//     int i;

//     if (pos >h->info)
//     {
//         printf("Invalid position.\n");
//         exit(1);
//     }

//     p=h->next;

//     for(i=1;i<pos;i++)
//     {
//         p=p->next;
//     }

//     q=p->prev;
//     q->next=p->next;
//     freenode(p);
//     h->info--;
// }

// int main()
// {
//     int num,i,n,pos,value,d;
//     struct node *list=NULL;
//     initlist(&list);
//     printf("How many number: ");
//     scanf("%d",&n);
//     printf("Enter number: ");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&num);
//         append(list,num);
//     }
//     printf("The link list: \n");
//     display(list);
//     printf("\nEnter position to Insert: ");
//     scanf("%d",&pos);
//     printf("\nEnter value to Insert: ");
//     scanf("%d",&value);
//     insert(list,value,pos);
//     printf("\nUpdated list is: ");
//     display(list);
//     printf("\nEnter position to Delete: ");
//     scanf("%d",&d);
//     delete(list,d);
//     printf("Updated list is: ");
//     display(list);
//     freenode(list);
//     return 0;
// }


struct queue
{
    int data[maxsz];
    int front,rear;
}

int isempty(struct queue *q)
{
    return q->rear===q->front;
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
        printf("Overflow!");
        exit(1);
    }
    q->data[q->rear]=value;
}

int deleq(struct queue *q)
{
    if(q->front==maxsz-1)
    {
        q->front=0;
    }
    else{
        q->fornt++;
    }
    if(isempty(q))
    {
        printf("Underflow!");
        exit(1);
    }
    return q->data[q->front];
}
void display(strutc queue *q)
{
    int i=0;
    while(i<=q->rear)
    {
        printf("%d ",q->data[i]);
        i++;
    }
}

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
    temp->next=NULL:
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
        printf("Underflow");
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



struct stack
{
    int data[maxsz];
    int top;
};

//struct stack
//void inits
//int isfull
//int isempty
//void push
//int pop
//int stacktop




void inits(struct stack *s)
{
    s->top=-1;
}

int isfull(struct stack *s)
{
    return s->top==maxsz-1;
}
int isempty(struct stack *s)
{
    return s->top==-1;
}

void push(struct stack *s,int value)
{
    if(isfull(s))
    {
        printf("Overflow!");
        exit(1);
    }
    s->data[++s->top]=value;
}

int pop(struct stack *s)
{
    if(isempty(s))
    {
        printf("Underflow!");
        exit(1);
    }
    return s->data[s->top--];
}

int stacktop(struct stack *s)
{
    if(isempty(s))
    {
        printf("Underflow!");
        exit(1);
    }
    return s->data[s->top];
}