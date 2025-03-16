#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char *fn, char op, char *pattern)
{
 int fh,count=0,i=0,j=0;
 char buff[255],c,*p;

 fh = open(fn,O_RDONLY);
 if(fh==-1)
 {
  printf("File %s Not Found\n",fn);
  return;
 }

 switch(op)
 {
 case 'f':
  while(read(fh,&c,1))
  {
   buff[j++]=c;
   if(c=='\n')
   {
    buff[j]='\0';
    j=0;
    i++;
    if(strstr(buff,pattern))
    {
     printf("%d: %s",i,buff);
     break;
    }
   }
  }
  break;
 case 'c':
  while(read(fh,&c,1))
  {
   buff[j++]=c;
   if(c=='\n')
   {
    buff[j]='\0';
    j=0;
    p = buff;
    while(p=strstr(p,pattern))
    {
     count++;
     p++;
    }
   }
  }
  printf("Total No.of Occurrences = %d\n",count);
  break;
 case 'a':
  while(read(fh,&c,1))
  {
   buff[j++]=c;
   if(c=='\n')
   {
    buff[j]='\0';
    j = 0;
    i++;
    if(strstr(buff,pattern))
     printf("%d: %s",i,buff);
   }
  }
 }//switch
 close(fh);
}//search



int main()
{
 char buff[80],tok1[10],tok2[10],tok3[10],tok4[10];
 int pid;

 while(1)
 {
  printf("myshell$");
  fflush(stdin);
  fgets(buff,80,stdin);
  n = sscanf(buff,"%s %s %s %s",tok1,tok2,tok3,tok4);
  if(strcmp(tok1,"search")==0)
   search(tok3,tok2,tok4);
  else
  {
   pid = fork();
   if(pid>0)
    wait(NULL);
   else
   {
  if(n==1)
  execlp(tok1,tok1,NULL);
if(n==2)
    execlp(tok1,tok1,tok2,NULL);
if(n==3)
    execlp(tok1,tok1,tok2,tok3,NULL);
   }
  }
 }

 return 0;
}

