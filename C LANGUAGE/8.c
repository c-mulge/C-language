//To calculate the area and perimeter of rectangle & area and circumference of circle
#include<stdio.h>
int main()
{
   int l, b, r, area, peri;
   float ac, c;

   printf("\n Enter the length of Rectangle=");
   scanf("%d", &l);
   printf("\n Enter the breadth of Rectangle=");
   scanf("%d", &b);
   printf("\n Enter the Radius of the circle=");
   scanf("%d", &r);

   area= l * b;
   peri= 2*(l + b);
   ac= 3.142 * r * r;
   c= 2 * 3.142 * r;

   printf("Area of Rectangle= %d\n", area);
   printf("Perimeter of Rectangle= %d\n", peri);
   printf("Area of circle= %f\n", ac);
   printf("Circumference of circle= %f\n", c);
   return 0;
} 