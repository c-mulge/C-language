//adding three numbers using functions
#include<stdio.h>
int calsum(int x, int y, int z);
int main()
{
    int a,b,c,sum;
    printf("Enter the number\n");
    scanf("%d %d %d",&a,&b,&c);
    sum=calsum(a,b,c);
    printf("Sum=%d",sum);
    return 0;
}
int calsum(int x, int y, int z)
{
    int d;
    d=x+y+z;
    return (d);
}