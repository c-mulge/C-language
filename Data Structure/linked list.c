//Ganpati Bappa Morya
//Linked list

#include<stdio.h>
#include<stdlib.h>
#define maxsz 50
struct node
{
    int info;
    struct node *next;
};
struct node *getnode(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=value;
    temp->next=0;
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

void append(struct node *head, int value)
{
    struct node *p = head;
    struct node *temp=getnode(value);
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    head->info++;
}

void display(struct node *head)
{
    struct node *p=head->next;
    while(p)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}

void sort(struct node *h)
{
    struct node *r=h;
    struct node *q=h->next;
    struct node *p=q->next;
    struct node *tail=NULL;
    while(h->next!=tail)
    {
        while(1)
        {
            if(q->info > p->info)
            {
                r->next=p;
                q->next=p->next;
                p->next=q;
            
                r=p;
                p=q->next;
            }
            else
            {
                r=q;
                q=q->next;
                p=q->next;  
            }
            if(p==tail)
            {
                tail=q;
                return;
            }
         }
         r=h;
         q=h->next;
         p=q->next;
         
    }
}

int linear(struct node *h,int ele)
{
    struct node *temp=h->next;
    int index=0;
    while(temp!=NULL)
    {
        if(temp->info==ele)
        {
            return index;
        }
        temp=temp->next;
        index++;
    }
    return -1;
}

int binary(struct node *h,int ele)
{
    int low=0;
    int high=0;
    int mid;
    struct node *temp=h;
    while(temp!=NULL)
    {
        high++;
        temp=temp->next;
    }
    high--;
    while(low<=high)
    {
        mid=(low+high)/2;
        temp=h;
        for(int i=0;i<mid;i++)
        {
            temp=temp->next;
        }

        if(temp->info==ele)
        {
            return mid;
        }

        if(temp->info<ele)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

void insert(struct node *h,int value,int pos)
{
    struct node *temp=0;
    struct node *p=0,*q=0;
    int i;
    if(pos>h->info)
    {
        printf("Invalid!");
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

void delete(struct node *h,int pos)
{
    struct node *p=0,*q=0;
    int i;
    if(pos>h->info)
    {
        printf("Invalid!");
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

int main()
{
    int num,pos,value,d,ele,index;
    struct node *list=NULL;
    initlist(&list);
    int choice;
    while(1)
    {
        printf("\nLinked List Operations: \n");
        printf("1. Append Linked List\n");
        printf("2. Add elements in Linked list\n");
        printf("3. Delete elements in Linked list\n");
        printf("4. Display Linked List\n");
        printf("5. Search\n");
        printf("6. Sorting of linked list\n");
        printf("7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter number: ");
                    scanf("%d",&num);
                    append(list,num);
                break;
            case 2:
                printf("\nEnter position to Insert: ");
                scanf("%d",&pos);
                printf("\nEnter value to Insert: ");
                scanf("%d",&value);
                insert(list,value,pos);
                break;
            case 3:
                printf("\nEnter position to Delete: ");
                scanf("%d",&d);
                delete(list,d);
                break;
            case 4:
                printf("\nThe link list: \n");
                display(list);
                printf("\n");
                break;
            case 5:
                printf("Enter element to find: ");
                scanf("%d",&ele);
                //index= linear(list,ele);
                index= binary(list,ele);
                if(index==-1)
                {
                    printf("The %d element did not found in the array.\n",ele);
                }
                else
                {
                    printf("The %d element is at %d position \n",ele,index);
                }
                break;
            case 6:
                printf("\nThe List is Sorted now.\n");
                for(int i=1;i<maxsz-1;i++)
                { 
                    sort(list);
                }
                break;
            case 7:
                freenode(list);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

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


