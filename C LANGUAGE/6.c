#include<stdio.h>
int main()
{
    int h;
    float sum;

     printf("Enter the height in cm\n");
     scanf("%d", &h);

       sum = h * 0.033;
       printf("%f", sum);
       return 0;
}