
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct noded *getnode(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=value;
    temp->next=NULL;
    return temp;
}

void initlist(struct node **head)
{
    (*head)=getnode(0);
}

void freenode(struct node *p)
{
    free(p);
}

void append(struct node *h,int value)
{
    struct node *p=head;
    struct node *temp=getnode(value);
    p=h;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    h->info++;
}

void display(struct node *h)
{
    struct node *p=h->next;
    while(p)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}

void insert(struct node *h,int value,int pos)
{
    struct node *temp=0, *p=0, *q=0;
    int i;
    if(pos>h->info)
    {
        printf("Invalid");
        exit(1);
    }
    temp=getnode(value);
    p=h->next;
    q=h;
    for(i=1;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    temp->next=p;
    q->next=temp;
    h->info++;
}

void delete (struct node *h,int pos)
{
    struct node *p=0, *q=0;
    int i;
    if(pos>h->info)
    {
        printf("Invalid");
        exit(1);
    }
    p=h->next;
    q=h;
    for(i=1;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    freenode(p);
    h->info--;
}