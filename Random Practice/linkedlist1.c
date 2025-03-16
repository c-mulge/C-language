#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp=NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=value;
    temp->next=NULL;
    return temp;
}

void freenode(struct node *p)
{
    free(p);
}
void initlist(struct node **head)
{
    (*head)=getnode(0);
}

void append(struct node *head,int value)
{
    struct node *p=head;
    struct node *temp=getnode (value);
    if(*head==NULL)
    {
        *head=temp;
    }
    else{
        while(p->next !=NULL)
        {
            p=p->next;
        }
    }
}