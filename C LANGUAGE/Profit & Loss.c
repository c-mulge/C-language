#include<stdio.h>
int main()
{
    float cp,sp,p,l;
    printf("Enter the cost price and selling price\n");
    scanf("%f %f",&cp,&sp);
    p=sp-cp;
    l=cp-sp;
    if(p>0)
     printf("The Profit is of amount= %f\n",p);
    if(l>0)
     printf("The loss is of amount= %f\n",l);
    if(p==0)
     printf("There is no profit and nor loss");
    return 0;
}