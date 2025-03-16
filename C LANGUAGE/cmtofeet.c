#include<stdio.h>  
int main()   
{  
int cm;  
double sum;   
printf("Enter the value in cm\n");
scanf("%d", &cm);
sum = 0.0328 * cm;    
printf ("Feet is: %f", sum);   
return 0;  
}  