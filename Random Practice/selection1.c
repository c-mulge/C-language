#include<stdio.h>
#define maxsz 20
// void selection(int a[],int n)
// {
//     int max,temp,i,j;
//     for(i=0;i<n;i++)
//     {
//         max=i;
//         for(j=i+1;j<n;j++)
//         {
//             if(a[j]<a[max])
//             {
//                 max=j;
//             }
//         }
//         temp=a[i];
//         a[i]=a[max];
//         a[max]=temp;
//     }
// }

void selection(int a[],int n)
{
    int max,i,j,temp;
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

int main()
{
    int a[maxsz];
    int i,n;
    printf("\nHow many Number: ");
    scanf("%d",&n);
    printf("\nEnter %d numbers: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection(a,n);
    printf("\nSorted list is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}