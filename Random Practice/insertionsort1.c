// #include<stdio.h>
// #define maxsz 10

// // void insertion(int a[],int n)
// // {
// //     int i,j;
// //     int temp;
// //     for(i=1;i<n;i++)
// //     {
// //         temp=a[i];
// //         for(j=i-1;j>=0 && a[j]>temp;j--)
// //         {
// //             a[j+1]=a[j];
// //         }
// //         a[j+1]=temp;
// //     }
// // }

// // int main()
// // {
// //     int i,n;
// //     int a[maxsz];
// //     printf("How many numbers: ");
// //     scanf("%d",&n);
// //     printf("Enter %d numbers: ",n);
// //     for(i=0;i<n;i++)
// //     {
// //         scanf("%d",&a[i]);
// //     }
// //     insertion(a,n);
// //     printf("Sorted list is: ");
// //     for(i=0;i<n;i++)
// //     {
// //         printf("%d ",a[i]);
// //     }
// //     return 0;
// // }

// void insert(int a[],int n)
// {
//     int i,j;
//     int hold;
//     for(i=1;i<n;i++)
//     {
//         hold=a[i];
//         for(j=i-1;j>=0 && a[j]>hold;j--)
//         {
//             a[j+1]=a[j];
//         }
//         a[j+1]=hold;
//     }
// }

// int main()
// {
//     int i,n;
//     int a[maxsz];
//     printf("How many numbers: ");
//     scanf("%d",&n);
//     printf("Enter %d numbers: ",n);
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&a[i]);
//     }
//     insert(a,n);
//     printf("Sorted list is: ");
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",a[i]);
//     }
//     return 0;
// }



// // void insert(int a[],int n)
// // {
// //     int i,j;
// //     int hold;
// //     for(i=1;i<n;i++)
// //     {
// //         hold=a[i];
// //         for(j=i-1;j>=0 && a[j]>hold;j--)
// //         {
// //             a[j+1]=a[j];
// //         }
// //         a[j+1]=hold;
// //     }
// // }

// void insert(int a[],int n)
// {
//     int i,j,hold;
//     for(i=1;i<n;i++)
//     {
//         hold=a[i];
//         for(j=i-1;j>=0 && hold<a[j];j--)
//         {
//             a[j+1]=a[j];
//         }
//         a[j+1]=hold;
//     }
// }



// int part(int a[],int lb,int ub)
// {
//     int pivot=a[lb],temp;
//     int down=lb;
//     int up=ub;

//     while(down<up)
//     {
//         while(pivot>=a[down] && down<=ub)
//         down++;
//         while(pivot<=a[up])
//         up--;
//         if(down<up)
//         {
//             temp=a[down];
//             a[down]=a[up];
//             a[up]=temp;
//         }
//     }
//     a[lb]=a[up];
//     a[up]=pivot;
//     return up;
// }

// int quick(int a[],int lb,int ub)
// {
//     int pass;
//     if(lb<ub)
//     {
//         pass=part(a,lb,ub);
//         quick(a,lb,pass-1);
//         quick(a,pass+1,ub);
//     }
// }




#include<stdio.h>
#define maxsz 20

void insertion(int a[],int n)
{
    int i,j,hold;
    for(i=1;i<n;i++)
    {
        hold=a[i];
        for(j=i-1;j>=0 && a[j]>hold;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=hold;
    }
}

int main()
{
    int a[maxsz];
    int n,i;
    printf("\nHow many numbers: ");
    scanf("%d",&n);
    printf("\nEnter %d numbers: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertion(a,n);
    printf("\nSorted list is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
