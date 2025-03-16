// Bubble sorting algorithm 
// Time complexity: O(n^2)
// Space complexity: O(1)

#include<stdio.h>
#define maxsz 10

void bubblesort(int a[],int n)
{
    int temp;
    int i,j,swapping=1;
        for(i=1;i<n && swapping;i++)            // swapping=1 means swap
        {                                       // swapping = 0 means no swap
            swapping=0;
            for(j=0;j<n-i;j++)
            {
                if(a[j]>a[j+1])             //change the sign to make the code in descending order
                {
                    swapping=1;           // if it is true then swapping is necessary
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
}

// swapping variable is used as flag to determine whether any swaps were made during a pass through array.

int main()
{
    int a[maxsz];
    int n,i;
        printf("How many numbers: ");
        scanf("%d",&n);

        printf("Enter %d numbers: \n",n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        bubblesort(a,n);
        printf("Sorted: \n");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    return 0;
}


