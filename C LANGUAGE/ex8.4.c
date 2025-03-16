#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() 
{
    int n, i, arr[100];
    // Get the number of elements in the array from the user
    printf("How many numbers: ");
    scanf("%d", &n);

    // Get the elements of the array from the user
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (i = 1; i < n; i++) 
    {
        max = MAX(max, arr[i]);
    }

    // Print the maximum number
    printf("Maximum number is: %d\n", max);
    return 0;
}
