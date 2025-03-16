#include <stdio.h>
main()
{
  int x,r,area,cofc;
  printf("Enter the option\n");
  scanf("%d",&x);
  switch(x)
  {case 1:printf("Enter the radius\n");
         scanf("%d",&r);
         area=3.14*r*r;
         printf("The area is=%d");
         break;
  case 2:printf("Enter the radius\n");
         scanf("%d",&r); 
         cofc=2*3.14*r;
        printf("The cofc is=%d");
        break;
      
}
}