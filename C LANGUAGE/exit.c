/* To accept two fractions and perform the following operations till the user selects exit*/
#include<stdio.h>
int main()
{
 int num1,deno1,num2,deno2;//for numerator and denominater
 int ch;
 int fnum,fdeno;//for final answer
 printf("Enter two fraction number\n");

 printf("1st numerator and denominater  :");
 scanf("%d %d",&num1,&deno1);//input for 1st fraction

 printf("2nd no. numerator and denominater  :");
 scanf("%d %d",&num2,&deno2);//input for 2nd fraction
 
 do
 {
  printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit\n");
  printf("\nEnter your choice:\n");//selecting the choices

  scanf("%d",&ch);
  
  switch(ch)
  {
   case 1: fnum=(num1*deno2)+(num2*deno1);
     fdeno=(deno1*deno2);
     printf("\nAddition of %d/%d and %d/%d is %d/%d\n",num1,deno1,num2,deno2,fnum,fdeno);
     break;//adding of fractions

   case 2: fnum=(num1*deno2)-(num2*deno1);
     fdeno=(deno1*deno2);
     printf("\nSubtraction of %d/%d and %d/%d is %d/%d\n",num1,deno1,num2,deno2,fnum,fdeno);
     break;//subtraction of fractions

   case 3: fnum=(num1*num2);
     fdeno=(deno1*deno2);
     printf("\nMultiplication of %d/%d and %d/%d is %d/%d\n",num1,deno1,num2,deno2,fnum,fdeno);
     break;//multiplication of fractions

   case 4: break;
  }
    } while(ch!=4);
}