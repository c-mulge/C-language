//take input from user of age, years of service and qualifications and decide the salary.

#include<stdio.h>
int main()
{
    char g;
    int yos, qual,sal=0;

        printf("Enter Gender, Years of Service and Qualifications (take 0=G and 1=PG): ");
        scanf("%c %d %d", &g, &yos, &qual);

            if(g=='m' && yos>=10 && qual==1)
                sal=11000;
            else if((g=='m' && yos>=10 && qual==0)||(g=='m' && yos<10 && qual==1))
                sal=10000;
            else if(g=='m' && yos<10 && qual==0)
                sal=7000;
            else if(g=='f' && yos>=10 && qual==1)
                sal=12000;
            else if(g=='f' && yos>=10 && qual==0)
                sal=9000;
            else if(g=='f' && yos<10 && qual==1)
                sal=10000;
            else if(g=='f' && yos<10 && qual==0)
                sal=6000;
            printf("\nSalary of Employee= %d\n",sal);
    return 0;
}