//finding area of triangle 
#include<stdio.h>
#include <math.h> //used for math formulae
int main()
{
    float a,b,c,sp,area;
    printf("Enter sides of triangle: \n");
    scanf("%f %f %f",&a,&b,&c);

    sp=(a+b+c)/2;
    area=sqrt(sp*(sp-a)*(sp-b)*(sp-c));

    printf("Area of triangle: %f\n",area);
    return 0;
}