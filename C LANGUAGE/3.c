#include <stdio.h>
int main()
{
    int n,i;
    printf("Enter the value of n\n");
    scanf("%d", &n);

printf("Even numbers are\n");
    for(i=2; i<=n; i=i+2)
    printf("%d\n",i);
}