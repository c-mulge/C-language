// // #include<stdio.h>
// // #define maxsz 10

// // void bubblesort(int a[],int n)
// // {
// //     int i,j,swapping=1;
// //     int temp;
// //     for(i=1;i<n && swapping;i++)
// //     {
// //         swapping=0;
// //         for(j=0;j<n-1;j++)
// //         {
// //             if(a[j]>a[j+1])
// //             {
// //                 swapping=1;
// //                 temp=a[j];
// //                 a[j]=a[j+1];
// //                 a[j+1]=temp;
// //             }
// //         }
// //     }
// // }

// // int main()
// // {
// //     int i,n;
// //     int a[maxsz];
// //     printf("How many numbers: ");
// //     scanf("%d",&n);
// // printf("Enter %d numbers: ",n);
// //     for(i=0;i<n;i++)
// //     {
// //         scanf("%d",&a[i]);
// //     }

// //     bubblesort(a,n);
// //     printf("Sorted numbers are: ");
// //     for(i=0;i<n;i++)
// //     {
// //         printf("%d ",a[i]);
// //     }
// //     return 0;
// // }

// // #include<stdio.h>
// // #define maxsz 10

// // void bubblesort(int a[],int n)
// // {
// //     int i,j,swapping=1;
// //     int temp;

// //     for(i=1;i<n && swapping;i++)
// //     {
// //         swapping=0;
// //         for(j=0;j<n-1;j++)
// //         {
// //             if(a[j]>a[j+1])
// //             {
// //                 swapping=1;
// //                 temp=a[j];
// //                 a[j]=a[j+1];
// //                 a[j+1]=temp;
// //             }
// //         }
// //     }
// // }

// // int main()
// // {
// //     int i,n;
// //     int a[maxsz];

// //     printf("How many number: ");
// //     scanf("%d",&n);
// //     printf("Enter %d number: ",n);
// //     for(i=0;i<n;i++)
// //     {
// //         scanf("%d",&a[i]);
// //     }
// //     bubblesort(a,n);
// //     printf("Sorted list is: ");
// //     for(i=0;i<n;i++)
// //     {
// //         printf("%d ",a[i]);
// //     }
// //     return 0;
// // }


// // #include<stdio.h>
// // #define maxsz 10

// // void bubblesort(int a[],int n)
// // {
// //     int i,j,swapping=1;
// //     int temp;

// //     for(i=1;i<n && swapping;i++)
// //     {
// //         swapping=0;
// //         for(j=0;j<n-i;j++)
// //         {
// //             if(a[j]>a[j+1])
// //             {
// //                     swapping=1;
// //                     temp=a[j];
// //                     a[j]=a[j+1];
// //                     a[j+1]=temp;
// //             }
// //         }
// //     }
// // }

// // int main()
// // {
// //     int i,n;
// //     int a[maxsz];

// //     printf("How many numbers: ");
// //     scanf("%d",&n);
// //     printf("Enter %d number: ",n);
// //     for(i=0;i<n;i++)
// //     {
// //         scanf("%d",&a[i]);
// //     }

// //     bubblesort(a,n);
// //     printf("Sorted list are: ");
// //     for(i=0;i<n;i++)
// //     {
// //         printf("%d ",a[i]);
// //     }
// //     return 0;
// // }


// #include<stdio.h>
// #define maxsz 10
// void bubblesort(int a[],int n)
// {
//     int i,j,swapping=1;
//     int temp;
//     for(i=1;i<n && swapping;i++)
//     {
//         swapping=0;
//         for(j=0;j<n-1;j++)
//         {
//             if(a[j]>a[j+1])
//             {
//                 swapping=1;
//                 temp=a[j];
//                 a[j]=a[j+1];
//                 a[j+1]=temp;
//             }
//         }
//     }
// }

// int main()
// {
//     int i,n;
//     int a[maxsz];
//     printf("How many nymbers: ");
//     scanf("%d",&n);
//     printf("Enter %d number: ",n);
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&a[i]);
//     }
//     bubblesort(a,n);
//     printf("Sorted list is: ");
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",a[i]);
//     }
//     return 0;
// }

// // void bubble(int a[],int n)
// // {
// //     int i,j,swapping=1;
// //     int temp;
// //     for(i=1;i<n && swapping;i++)  //swapping
// //     {
// //         swapping=0;
// //         for(j=0;j<n-1;j++)    //j<n-1
// //         {
// //             if(a[j]>a[j+1])
// //             {
// //                 swapping=1;
// //                 temp=a[j];
// //                 a[j]=a[j+1]
// //                 a[j+1]=temp;

// //             }
// //         }
// //     }
// // }



// void bubble(int a[], int n)
// {
//     int i,j,swapping=1;
//     int temp;

//     for(i=1;i<n && swapping;i++)
//     {
//         swapping=0;
//         for(j=0;j<n-1;j++)
//         {
//             if(a[j]>a[j+1])
//             {
//                 temp=a[j];
//                 a[j]=a[j+1];
//                 a[j+1]=temp;
//             }
//         }
//     }
// }


#include<stdio.h>
#define maxsz 20

void bubblesort(int a[],int n)
{
    int temp;
    int i,j,swapping=1;
    for(i=1;i<n && swapping;i++)
    {
        swapping=0;
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swapping=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
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
    bubblesort(a,n);
    printf("\nSorted list is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}