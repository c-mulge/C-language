//Selection sort for ascending and descending

#include<stdio.h>
#define maxsz 50
void selection(int a[],int n);
void display(int a[],int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void accept(int a[],int n)
{
    int i;
    printf("Enter %d numbers: \n",n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
}
// void selectionsort(int a[], int n)
// {
//     int max,temp;
//     for(int i=0;i<n;i++)
//     {
//         max=i;
//         for(int j=i+1;j<n;j++)
//         {
//             if(a[j]<a[max])    //change sign to make the code run in descending order
//             {
//                 max=j;
//             }
//         }
//         //swapping a[i] and a[max]
//         temp=a[i];
//         a[i]=a[max];
//         a[max]=temp;
//     }
// }

int main()
{
    int a[maxsz];
    int n;
        printf("How many numbers: ");
        scanf("%d",&n);

        accept(a,n);
        selection(a,n);

        printf("\nSorted list is: ");
        display(a,n);

    return 0;
}


void selection(int a[],int n)
{
    int temp;
    int i,j,k;
    for(j=0;j<n;j++)
    {
        i=0;
        for(k=0;k<n-j;k++)
        {
            if(a[i]<a[k])
            {
                i=k;
            }
        }
        temp=a[i];
        a[i]=a[n-j-1];
        a[n-j-1]=temp;
    }
}