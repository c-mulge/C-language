#include<stdio.h>
int main()
{
    int avg, sum=0;
    int i;
    int marks[30]; //array declaration
    for(i=0;i<=5;i++)
    {
        printf("Enter marks");
        scanf("%d", &marks[i]);
           
            }
    for(i=0;i<=29; i++)
    sum=sum+marks[i];//read data from an array
    avg=sum/30;
    printf("Average marks=%d\n",avg);
    return 0;
    
    }
