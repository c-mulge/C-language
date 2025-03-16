#include<stdio.h>
int main()
{
 int a, b, c, d, e, avg;
 float per;

 printf("\n Enter marks in 5 subjects:");
 scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
 avg= a + b + c + d + e;
 per= avg/5;
 printf("Average marks= %d\n", avg);
 printf("Percentage= %f\n", per);
 return 0;
}