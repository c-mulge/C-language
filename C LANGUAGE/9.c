#include<stdio.h>
int main()
{
    float f, c;
    printf("Enter the Temperature=");
    scanf("%f", &f);
    c=((f-32)*5)/9;
    printf("Temperature in Celecius= %f", c);
    return 0;
}

 