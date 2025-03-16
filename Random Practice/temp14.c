#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSZ 20
struct node
{
    int info;
    struct node*left;
    struct node*right;
};
struct stack
{
    struct node* data;
    struct stack* next;
};
void initstack(struct stack **s)
{
  //(*s)->next=NULL;
  *s=NULL;
}

void freenode(struct stack *s)
{
    free(s);
}

int isempty(struct stack **s)
{
    //return (*s)->next==NULL;
    return *s==NULL;
}
void push(struct stack **s,struct node*value)
{
   struct stack*temp=(struct stack*)malloc(sizeof(struct stack));
   temp->data=value;
   temp->next=*s;
   *s=temp;
}/*
int pop(struct stack **s)
{
    int value;
    struct stack *temp;
    if(isempty(s))
    {
        printf("Stack Underflow!");
        exit(1);
    }
    value=(*s)->data->info;
    temp=*s;
    (*s)=(*s)->next;
    freenode(temp);
    return value;
}*/

struct node* pop(struct stack** s)
{
    struct node* value;
    struct stack* temp;
    if (isempty(s))
    {
        printf("Stack Underflow!");
        exit(1);
    }
    value = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    freenode(temp);
    return value;
}

void inorder(struct node *tree)
{
    struct node *p=tree;
    struct stack *stk;
    initstack(&stk);
    do
    {
        while(p)
        {
            push(&stk,p);
            p=p->left;
        }
        p = pop(&stk);
        if (p != NULL)
        {
            printf("%d\t", p->info);
            p = p->right;
        }
    }
    while(p!=NULL||!isempty(&stk));
}

struct node*maketree(int value)
{
    struct node*temp=(struct node*)malloc(sizeof (struct node));
    temp->info=value;
    temp->left= NULL;
    temp->right= NULL;
    return temp;
}
int isleft(struct node*root)
{
    return root->left!= NULL;
}
int isright(struct node*root)
{
    return root->right!= NULL;
}
void setleft(struct node*root,int value)
{
    if(isleft(root))
    {
        printf("Left root already exists!");
        exit(1);
    }
    root->left=maketree(value);
}

void setright(struct node*root,int value)
{
    if(isright(root))
    {
        printf("rIGHT root already exists!");
        exit(1);
    }
    root->right=maketree(value);
}
struct node*bst(int a[],int n)
{
    struct node*p=0;
    int i;
    struct node*root=maketree(a[0]);
    for(i=1;i<n;i++)
    {
        p=root;
        while(1)
        {
            if(p->info<=a[i])
            {
                if(isright(p))
                   {
                    p=p->right;
                   }
                else
                   {
                    setright(p,a[i]);
                    break;
                   }
            }
            else
            {
                if(isleft(p))
                   {
                       p=p->left;
                   }
                else
                    {
                        setleft(p,a[i]);
                        break;
                    }
            }

        }
    }return root;
}

void preorder(struct node*tree)
{
    struct node*p=tree;
    struct stack *stk;
    initstack(&stk);
    do
    {
        while(p)
        {
            printf("%d\t",p->info);
            push(&stk,p);
            p=p->left;
        }
        p=pop(&stk);
        if (p != NULL)
        {
            p = p->right;
        }
    }
    while(p!=NULL||!isempty(&stk));
}

struct node *peek(struct stack **s)
{
    return (*s)->data;
}

void postorder(struct node* tree)
{
    struct node* p = tree;
    struct stack *stk;
    initstack(&stk);

    do
    {
        while (p)
        {
            if (p->right)
                push(&stk, p->right);
            push(&stk, p);
            p = p->left;
        }

        p = pop(&stk);

        if (p->right && !isempty(&stk) && p->right == peek(&stk))
        {
            pop(&stk);
            push(&stk, p);
            p = p->right;
        }
        else
        {
            printf("%d\t", p->info);
            p = NULL;
        }
    } while (!isempty(&stk));
}



int main()
{
    struct node* root = 0;
    int i, n, a[MAXSZ];
    printf("Enter the limit\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    root = bst(a, n);
    printf("inorder form\n");
    inorder(root);
    printf("\nPreorder form\n");
    preorder(root);
    printf("\nPostorder form\n");
    postorder(root);
    return 0;
}