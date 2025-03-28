// Linear hashing

#include <stdio.h>
#include <stdlib.h>
#define maxsz 10

int hash(int n)
{
    return n % 10;
}

int rehash(int n)
{
    return (n + 1) % 10;
}

int search(int arr[], int key)
{
    int ch = hash(key);
    while (1)
    {
        if (arr[ch] == key)
            return arr[ch];
        else if (arr[ch] != -1)
            ch = rehash(ch);
        else
            return -1;
    }
}

int main()
{
    int arr[10];
    int i, n, ch, temp = 0, num;
    int choice;
    while (1)
    {
        printf("\n1. Insert hash");
        printf("\n2. Display hash");
        printf("\n3. Search element");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("How many elements: ");
            scanf("%d", &n);
            printf("Enter the elements: ");
            for (i = 0; i < maxsz; i++)
            {
                arr[i] = -1;
            }
            for (i = 0; i < n; i++)
            {
                scanf("%d", &temp);
                ch = hash(temp);
                while (1)
                {
                    if (arr[ch] == -1)
                    {
                        arr[ch] = temp;
                        break;
                    }
                    else
                    {
                        ch = rehash(ch);
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < maxsz; i++)
            {
                printf("%d ", arr[i]);
            }
            break;
        case 3:
            printf("Enter searching element: ");
            scanf("%d", &num);
            int k = search(arr, num);
            if (k == -1)
            {
                printf("Element is not present");
            }
            else
            {
                printf("Element %d is present", num);
            }
            // k ? printf("Element:%d is present", k) : printf("Element is not present");
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
