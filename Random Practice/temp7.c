#include<stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp=(stutc node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->inLL;fo=value;
    temp->next=NU
    return temp;
}

void freenode(struct node *p)
{
    free(p);
}

void initlist(struct node **h)
{
    (*h)=getnode(0);
}

void append(struct node *h,int value)
{
    struct node *p=h;
    struct node *temp=getnode(value);
    if(h==NULL)
    {
        h=temp;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
        h->info++;
    }
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
    p=h->next;
    for(i=1;i<pos;i++)
    {
        p=p->next;
    }
    temp=getnode(value);
    q=p->prev;
    temp->next=p;
    temp->prev=q;
    p->prev=temp;
    q->next=temp;
    h->info++;
}

void delete(struct node *h,int pos)
{
    struct node *p=h->next; 
    struct node *q=h;
    int i;
    if(pos>h->info)
    {
        printf("Invalid");
        exit(1);
    }
    p=h->next;
    for(i=1;i<pos;i++)
    {
        p=p->next;
    }
    q=p->prev;
    q->next=p->next;
    freenode(p);
    h->info--;
}

void reverse(struct node *h)
{
    if(!h)
    {
        return;
    }
    reverse(h->next);
    printf("%d ",h->info);
}