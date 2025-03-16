//determine wheather the driver is insured or not
#include<stdio.h>
int main()
{
  char sex,ms;
  int age;

  printf("Enter the age, sex and married status of the driver\n");
  scanf("%d %c %c",&age,&sex,&ms);
  if((ms=='M')||(ms=='U' && sex=='M' && age>30)||(ms=='U' && sex=='F' && age>25))
     printf("Driver is Insured");
  else
     printf("Driver is not Insured");

     return 0;

}