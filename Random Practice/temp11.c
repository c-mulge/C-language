#include<stdio.h>
#include<stdlib.h>
#define maxsz 100

void dpqinsert(int a[],int x,int n)
{
  while(1)
  {
    if(n==0)
    {
      a[n]=x;
      break;
    }
    else if(a[(n-1)/2]>x)       //<=x
    {
      a[n]=a[(n-1)/2];
      n=(n-1)/2;
    }
    else
    {
      a[n]=x;
      break;
    }
  }
}

int dpqdel(int x[],int n)
{
  int temp,i=0;
  temp=x[0];
  while(1)
  {
    if((i*2+1)>n|| (i*2+2)>n)
    {
      dpqinsert(x,x[n],i);
      break;
    }
    else if(x[i*2+1] < x[i*2+2])    //>
    {
      x[i]=x[i*2+1];
      i=i*2+1;
    }
    else
    {
      x[i]=x[i*2+2];
      i=i*2+2;
    }
  } return temp;
}

int main()
{
  int i,num,n;
  int a[maxsz];
  printf("How many number: ");
  scanf("%d",&n);
  printf("Elements: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&num);
    a[i]=num;
  }
  for(i=0;i<n;i++)
  {
    dpqinsert(a,a[i],i);
  }
  printf("Heap Tree: ");
  for(i=(n-1);i>=0;i--)
  {
    a[i]=dpqdel(a,i);
  }
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}