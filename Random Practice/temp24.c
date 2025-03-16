#include <stdio.h>
#include <stdlib.h>
#define maxsz 50
int linear(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n && a[i] < key; i++)
        ;
    if (a[i] == key)
        return i;
    return -1;
}

void accept(int a[],int n)
{
    int i,j,hold;
    for(i=0;;i<n;i++){
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
        printf("%d ",a[i]);
}

