#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsz 50

// int linear(int a[],int n,int key)
// {
//     int i;
//     for(i=0;i<n && a[i]<key;i++);
//     if(a[i]==key)
//         return i;
//     return -1;
// }

// void accept(int a[],int n)
// {
//     int i,j;
//     int hold;
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&hold);
//         for(j=i-1;j>=0 &&a[j]>hold;j--)
//         {
//             a[j+1]=a[j];
//         }
//         a[j+1]=hold;
//     }
// }

// void display(int a[],int n)
// {
//     int i;
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",a[i]);
//     }
// }

// int main()
// {
//     int a[maxsz];
//     int n,choice,key,res;
//     while(1)
//     {
//         printf("\nOpertaions are: ");
//         printf("\n1.Insert");
//         printf("\n2.Serach");
//         printf("\n3.Display");
//         printf("\n4.Exit");
//         printf("\nEnter your choice: ");
//         scanf("%d",&choice);
//         switch(choice)
//         {
//             case 1:
//                 printf("Enter the size of array: ");
//                 scanf("%d",&n);
//                 printf("\nEnter %d numbers: ",n);
//                 accept(a,n);
//                 break;
//             case 2:
//                 printf("Enter the key to search: ");
//                 scanf("%d",&key);
//                 res=linear(a,n,key);
//                 if(res!=-1)
//                 {
//                     printf("\nThe %d is at %d index.",key,res);
//                 }
//                 else
//                     printf("\nThe %d is not in the given array.",key);
//                 break;
//             case 3:
//                 printf("\nThe elements are: ");
//                 display(a,n);
//                 break;
//             case 4:
//                 exit(1);
//                 break;
//             default:
//                 printf("Invalid choice!!!");
//         }
//     }return 0;
// }




struct node{
    int info;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=value;
    temp->next=NULL;
    return temp;
}

void freenode(struct node *h)
{
    free(h);
}

void initlist(struct node **h)
{
    (*h)=getnode(0);
}

void append(struct node *h,int value)
{
    struct node *p=h;
    struct node *temp=getnode(value);
    struct node *q=0;
    int i;
    if(p->next==NULL)
    {
        p->next=temp;
        h->info++;
        return;
    }
    p=h->next;
    q=h;
    for(i=1;i<=h->info && p->info<=value;i++)
    {
        q=p;
        p=p->next;
    }
    temp->next=p;
    q->next=temp;
    h->info++;
}

void display(struct node *h)
{
    h=h->next;
    while(h)
    {
        printf("%d ",h->info);
        h=h->next;
    }
}

int search(struct node *h,int value)
{
    struct node *temp;
    int pos;
    for(temp=h->next,pos=1;temp!=0;temp=temp->next,pos++)
        if(value==temp->info)
            return pos;
    return -1;
}

int main()
{
    struct node *list=NULL;
    initlist(&list);
    int choice;
    int num,key;
    while(1)
    {
        printf("\nOpertaions are: ");
        printf("\n1.Append");
        printf("\n2.Serach");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d",&num);
                append(list,num);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d",&key);
                int res=search(list,key);
                if(res!=-1)
                {
                    printf("\nThe %d is at %d index.",key,res);
                }
                else
                    printf("\nThe %d is not in the given array.",key);
                break;
            case 3:
                printf("\nThe elements are: ");
                display(list);
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid choice!!!");
        }
    }return 0;    
}


int binary(int a[],int lb,int ub, int key)
{
    int mid;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
                ub=mid-1;
            else
                lb=mid+1;
    }
    return -1;
}

void accept(int a[],int n)
{
    int i,j;
    int hold;
    for(i=0;i<n;i++)
    {
        scanf("%d",&hold);
        for(j=i-1;j>=0 && a[j]>hold;j--)
            a[j+1]=a[j];
        a[j+1]=hold;
    }
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int a[maxsz];
    int n,choice,key,res;
    while(1)
    {
        printf("\nOpertaions are: ");
        printf("\n1.Insert");
        printf("\n2.Serach");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the size of array: ");
                scanf("%d",&n);
                printf("\nEnter %d numbers: ",n);
                accept(a,n);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d",&key);
                res=binary(a,0,n-1,key);
                if(res!=-1)
                {
                    printf("\nThe %d is at %d index.",key,res);
                }
                else
                    printf("\nThe %d is not in the given array.",key);
                break;
            case 3:
                printf("\nThe elements are: ");
                display(a,n);
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid choice!!!");
        }
    }return 0;
}