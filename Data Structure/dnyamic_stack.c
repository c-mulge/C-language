//Dynamic Stack

#include<stdio.h>
#include<stdlib.h>
#define maxsz 10

struct stack
{
    int info;
    struct stack *next;
};

void freenode(struct stack *s)
{
    free(s);
}

struct stack *getnode(int value)
{
    struct stack *temp=NULL;
    temp=(struct stack *)malloc(sizeof(struct stack));
    temp->info=value;
    temp->next=0;
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

void push(struct stack **s,int value)
{
    struct stack *temp=getnode(value);
    temp->next=*s;
    *s=temp;
}

int pop(struct stack **s)
{
    int value;
    struct stack *temp;
    if(isempty(s))
    {
        printf("Stack Underflow!");
        exit(1);
    }
    value=(*s)->info;
    temp=*s;
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
    printf("Stack underflow!");
    exit(1);
}

int main()
{
    int str;
    struct stack *stk=(struct stack *)malloc(sizeof(struct stack));
    initstack(&stk);
    int choice;
    while(1)
    {
        printf("\nStack operations: ");
        printf("\n1. Push element in stack.");
        printf("\n2. Pop element from stack.");
        printf("\n3. Stacktop.");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:                                       //Push operation
                printf("Enter element: ");
                scanf("%d",&str);
                push(&stk,str);
                break;
            case 2:                                          //POP operation
                printf("\nPop element: %d",pop(&stk));
                printf("\n");
                break;
            case 3:                                       //stacktop opeartion. It display's / point to the topmost element of the stack.
                printf("Stacktop: %d",stacktop(&stk));
                break;
            case 4:                //exit from program
                exit(0);
                break;
            default: 
                printf("Invalid Choice");          //if user gives incorrect choice then!
                break;
        }
    }return 0;
}

