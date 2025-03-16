#include<stdio.h>
#include<stdlib.h>
#define maxsz 50

void searchKey(int arr[], int size, int key) {
    int count = 0;
    printf("Positions of key %d in the array: ", key);

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("%d ", i);  // Adding 1 to the index to display positions starting from 1
            count++;
        }
    }

    if (count == 0) {
        printf("Key not found in the array.\n");
    } else {
        printf("\nNumber of occurrences: %d\n", count);
    }
}

int main()
{
    int n;
    int a[maxsz];
    printf("Enter sizer of array: ");
    scanf("%d",&n);
    printf("Enter the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int key;
    printf("Enter ele to search: ");
    scanf("%d",&key);
    searchKey(a, n, key);
    // int res=count(a,n,key);
    // printf("The element has occured %d times.\n",res);
    return 0;
}