#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct process_info
{
 char pname[20];
 int at,bt,ct,bt1;
 struct process_info *next;
}NODE;

int n;
NODE *first,*last;

void accept_info()
{
 NODE *p;
 int i;
 printf("Enter no.of process:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  p = (NODE*)malloc(sizeof(NODE));
  printf("Enter process name,arrival time,burst time");
  scanf("%s%d%d",p->pname,&p->at,&p->bt);
  p->bt1 = p->bt;
  p->next = NULL;
  if(first==NULL)
   first=p;
  else
   last->next=p;
  last = p;
 }
}

void print_output()
{
 NODE *p;
 float avg_tat=0,avg_wt=0;
 printf("pname\tat\tbt\tct\ttat\twt\n");
 p = first;
 while(p!=NULL)
 {
  int tat = p->ct-p->at;
  int wt = tat-p->bt;
  avg_tat+=tat;
  avg_wt+=wt;
  printf("%s\t%d\t%d\t%d\t%d\t%d\n",p->pname,p->at,p->bt,p->ct,tat,wt);
    p=p->next;
 }
 printf("Avg TAT=%f\tAvg WT=%f\n", avg_tat/n,avg_wt/n);
}
void sort()
{
 NODE *p,*q;
 int t;
 char name[20];
 p = first;
 while(p->next!=NULL)
 {
  q=p->next;
  while(q!=NULL)
  {
   if(p->at > q->at)
   {
    strcpy(name,p->pname);
    strcpy(p->pname,q->pname);
    strcpy(q->pname,name);
    t = p->at;
    p->at = q->at;
    q->at = t;
    t = p->bt;
    p->bt = q->bt;
    q->bt = t;
    t = p->ct;
    p->ct = q->ct;
    q->ct = t;
    t = p->bt1;
    p->bt1 = q->bt1;
    q->bt1 = t;
    }
   q=q->next;
  }
   p=p->next;
 }
}
int time;
NODE * get_sjf()
{
 NODE *p,*min_p=NULL;
 int min=9999;
 p = first;
 while(p!=NULL)
 {
  if(p->at<=time && p->bt1!=0 &&   p->bt1<min)
  {
   min = p->bt1;
   min_p = p;
  }
  p=p->next;
 }
 return min_p;
}
void sjfnp()
{
 NODE *p;
 int n1=0;
 while(n1!=n)
 {
  p = get_sjf();
  if(p==NULL)
  {
   time++;
  }
  else
  {
   printf("\n %d___%s",time,p->pname);
   time+=p->bt1;
   p->ct = time;
   printf("___%d",p->ct);
   p->bt1 = 0;
   n1++;
  }
   sort();
 }
}
int main()
{
 accept_info();
 sort();
 sjfnp();
 print_output();
 return 0;
}
