/* To accept x and y coordinates of two points and perform the following operations till the user selects exit*/
#include<stdio.h>
#include<math.h>
int main()
{
 double x1,y1,x2,y2,res;
 int ch;
 printf("\nEnter Point A:");
 scanf("%f %f",&x1,&y1);
 printf("\nEnter Point B:");
 scanf("%f %f",&x2,&y2);
 printf("\n1.Distance\n2.Slop\n3.Quadrant\n4.Exit");
 
while(ch!=4)
      {
       printf("\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
         {
          case 1:res=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
            res=sqrt(res);
             printf("\nDistance is %lf:",res);
             break;
          case 2:res=(y2-y1)/(x2-x1);
             printf("\nSlop is %lf:",res);
             break;
          case 3:if(x1>0 &&x2>0 &&y1>0 &&y2>0)
            printf("\nIn same quadrant and in First quadrant:");
   break;
         }
       }
}