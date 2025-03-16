#include <stdio.h>
int main()
{
    float hra,da,bs,gs;
    printf("Enter the Basic salary\n");
    scanf("%f",&bs);
         
         if(bs<1500)
          { hra=bs*10/100;
           da=bs*90/100;
           }
        else
          { hra=500;
            da=bs*98/100;
           }

           gs=bs+hra+da;
           printf("The Gross amount is=%f",gs);
           return 0;
}