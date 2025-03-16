// #include<stdio.h>
// #define maxsz 50

// // void merge(int a[],int low,int mid, int high)
// // {
// //     int i,j,k;
// //     int b[maxsz];
// //     i=low;
// //     j=mid+1;
// //     k=0;
// //     while(i<=mid && j<=high)
// //     {
// //         if(a[i]<a[j])
// //         {
// //             b[k++]=a[i++];
// //         }
// //         else{
// //             b[k++]=a[j++];
// //         }
// //     }
// //     while(i<=mid)
// //     {
// //         b[k++]=a[i++];
// //     }
// //     while(j<=high)
// //     {
// //         b[k++]=a[j++];
// //     }
// //     for(i=low,k=0;i<=high;i++,k++)
// //     {
// //         a[i]=b[k];
// //     }
// // }

// // void merge(int a[],int low,int high)
// // {
// //     int mid;
// //     if(low<high)
// //     {
// //         mid=(low+high)/2;
// //         mergesort(a,low,mid);
// //         mergesort(a,mid+1,high);
// //         merge(a,low,mid,high);
// //     }
// // }


// // void merge(int a[],int low,int mid,int high)
// // {
// //     int i,j,k;
// //     int b[maxsz];
// //     i=low,j=mid+1,k=0;
// //     while(i<=mid && j<=high)
// //     {
// //         if(a[i]<a[j])
// //         {
// //             b[k++]=a[i++];
// //         }
// //         else{
// //             b[k++]=a[j++];
// //         }
// //     }
// //     while(i<=mid)
// //     {
// //         b[k++]=a[i++];
// //     }
// //     while(j<=high)
// //     {
// //         b[k++]=a[j++];
// //     }
// //     for(i=low,k=0;i<=high;i++,k++)
// //     {
// //         a[i]=b[k];
// //     }
// // }

// // void mergesort(int a[],int low,int high)
// // {
// //     int mid;
// //     if(low<high)
// //     {
// //         mid=(low+high)/2;
// //         mergesort(a,low,mid);
// //         mergesort(a,mid+1,high);
// //         merge(a,low,mid,high);
// //     }
// // }

// // int main()
// // {
// //     int i, a[maxsz],n;
// //     printf("How many numbers: ");
// //         scanf("%d",&n);
// //     printf("Enter %d numbers: \n",n);
// //     for(i=0;i<n;i++)
// //         {
// //             scanf("%d",&a[i]);
// //         }
// //     mergesort(a, 0, n-1);
// //    printf("\nSorted Array: ");
// //     for (i = 0; i < n; i++) 
// //     {
// //         printf("%d ", a[i]);
// //     }
// //     return 0;
// // }


// void merge(int a[],int low,int mid,int high)
// {
//     int i,j,k;
//     int b[maxsz];
//     i=low;
//     j=mid+1;
//     k=0;

//     while(i<=mid && j<=high)
//     {
//         if(a[i]<a[j])           //change sign to make code descending order
//         {
//             b[k]=a[i];
//             k++;
//             i++;
//         }
//         else{
//             b[k]=a[j];
//             k++;
//             j++;
//         }
//     }
//     while(i<=mid)
//     {
//         b[k]=a[i];
//         k++;
//         i++;
//     }
//     while(j<=high)
//     {
//         b[k]=a[j];
//         k++;
//         j++;
//     }
//     for(i=low,k=0;i<=high;i++,k++)
//     {
//         a[i]=b[k];
//     }
// }

// void mergesort(int a[],int low,int high)
// {
//     int mid;
//     if(low<high)
//     {
//         mid=(low+high)/2;
//         mergesort(a,low,mid);
//         mergesort(a,mid+1,high);
//         merge(a,low,mid,high);
//     }
// }

// int main()
// {
//     int i, a[maxsz],n;
//     printf("How many numbers: ");
//         scanf("%d",&n);
//     printf("Enter %d numbers: \n",n);
//     for(i=0;i<n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
//     mergesort(a, 0, n-1);
//    printf("\nSorted Array: ");
//     for (i = 0; i < n; i++) 
//     {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }

#include <stdio.h>
#define maxsz 20

void merge(int a[],int low,int mid,int high)
{
    int i,j,k;
    int b[maxsz];
    i=low;
    k=0;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=high)
    {
        b[k++]=a[j++];
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=b[k];
    }
}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    int n,i;
    int a[maxsz];
    printf("\nHow many numbers: ");
    scanf("%d",&n);
    printf("\nEnter %d numbers: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nSorted list: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}