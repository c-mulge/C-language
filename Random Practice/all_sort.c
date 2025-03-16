//Bubble sort

void bubble(int a[],int n)
{
    int i,j,swapping=1;
    int temp;

    for(i=1;i<n && swapping;i++)
    {
        swapping=0;
        for(j=0;j<n-1;j++)
        {
            if(a[j+1]<a[j])              //change sign to make code descending
            {
                swapping=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

//insertion sort

void insert(int a[],int n)
{
    int i,j;
    int hold;

    for(i=1;i<n;i++)
    {
        hold=a[i];
        for(j=i-1;j>=0 && hold<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=hold;
    }
}

// quciksort

int part(int a[],int lb,int ub)
{
    int pivot=a[lb],temp;
    int down=lb;
    int up=ub;

    while(down<up)
    {
        while(pivot>=a[down] && down<=ub)
        down++;
        while(pivot<a[up])
        up--;
        if(down<up)
        {
            temp=a[down];
            a[down]=a[up];
            a[up]=temp;
        }
    }
    a[lb]=a[up];
    a[up]=pivot;
    return up;
}

void quicksort(int a[],int lb,int up)
{
    int pass;
    if(lb<ub)
    {
        pass=part(a,lb,ub);
        quicksort(a,lb,pass-1);
        quicksort(a,pass+1,ub);
    }
}

//merge sort
void merge(int a[],int low,int mid,int high)
{
    int i,j,k;
    int b[maxsz];
    i=low;
    j=mid+1;
    k=0;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else{
            b[k]=a[j];
            k++;
            i++;
        }
    }

    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }

    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=b[k];
    }
}

void mergesort(int a[],int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        meregesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}


//selection sort
void selection(int a[],int n)
{
    int max,temp,i,j;
    for(i=0;i<n;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[max])
            {
                max=j;
            }
        }
        temp=a[i];
        a[i]=a[max];
        a[max]=temp;
    }
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsz 5

struct stack
{
    char data[maxsz];
    int top;
};

void initstack(struct stack *s)
{
    s->top = -1;
}

int isfull(struct stack *s)
{
    return s->top == maxsz - 1;
}

int isempty(struct stack *s)
{
    return s->top == -1;
}

void push(struct stack *s, char value)
{
    if (isfull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++s->top] = value;
}

char pop(struct stack *s)
{
    char i;
    if (isempty(s))
    {
        printf("Stack Underflow!\n");
        return 1;
    }
    i = s->data[s->top];
    s->top -= 1;
    return i;
}

int main()
{
    char str[maxsz];
    int i = 0;
    struct stack stk;
    initstack(&stk);
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (strlen(str) > maxsz)
    {
        printf("Input string is too long for the stack!\n");
        return 1;
    }

    while (str[i] != '\0')
    {
        push(&stk, str[i]);
        i++;
    }
    
    printf("Reversed string: ");
    while (!isempty(&stk))
        printf("%c", pop(&stk));
    printf("\n");
    
    return 0;
}
