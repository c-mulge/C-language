//dynamic stack

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int info;
    struct stack *next;
};

struct stack *getnode(int value)
{
    struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
    temp->info=value;
    temp->next=NULL;
    return temp;
}

void initstack(struct stack **s)
{
    (*s)->next=NULL;
}

int isempty(struct stack **s)
{
    return (*s)->next==NULL;
}

void freenode(struct stack *s)
{
    free(s);
}

void push(struct stack **s,int value)
{
    struct stack *temp=getnode(value);
    temp->next=(*s);
    (*s)=temp;
}

int pop(struct stack **s)
{
    int value;
    struct stack *temp;
    if(isempty(s))
    {
        printf("Underflow");
        exit(1);
    }
    value=(*s)->info;
    temp=(*s);
    (*s)=(*s)->next;
    freenode(temp);
    return value;
}

int stacktop(struct stack **s)
{
    if(!isempty(s))
    {
        return (*s)->info;
    }
    printf("Empty");
    exit(1);
}

int main()
{
    struct stack *s;
    initstack(&s);
    int choice,num;

    while(1)
    {
        printf("\n\n Operations are: ");
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Stacktop");
        printf("\n 4.Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter number to push: ");
                scanf("%d", &num);
                push(&s,num);
                break;
            case 2:
                printf("\nPop: %d",pop(&s));
                break;
            case 3:
                printf("\nStack Top: %d",stacktop(&s));
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("\n Invalid Choice");
        }
    } return 0;
}
