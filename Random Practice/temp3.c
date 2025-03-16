//Static Stack

#include <stdio.h>
#include <stdlib.h>
#define maxsz 100

struct stack
{
    int data[maxsz];
    int top;
};

void initstack(struct stack *s)
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
        printf("Stack overflow");
        exit(1);
    }
    s->data[++s->top]=value;
}

int pop(struct stack *s)
{
    if(isempty(s))
    {
        printf("Stack underflow");
        exit(1);
    }
    return s->data[s->top--];
}

int stacktop(struct stack *s)
{
    if(isempty(s))
    {
        printf("Stack underflow");
        exit(1);
    }
    return s->data[s->top];
}

int main()
{
    struct stack s;
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