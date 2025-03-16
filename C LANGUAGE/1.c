/* To calculate the Am and Hm*/
#include<stdio.h>
int main()
{
    float a,b,am,hm;
    printf("Enter the value of 1st number\n");
    scanf("%f", &a);

    printf("Enter the value of 2nd number\n");
    scanf("%f", &b);

    am=(a+b)/2;
    hm=(a*b)/(a+b);

    printf("Am of two nuber is=%f\n",am);
    printf("Hm of two nuber is=%f\n",hm);
    return 0;
}