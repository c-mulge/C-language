#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>

void list(char *dn, char op)
{
 DIR *dp;
 struct dirent *entry;
 int dc=0,fc=0;

 dp = opendir(dn);
 if(dp==NULL)
 {
  printf("Dir %s not found.\n",dn);
  return;
 }

 switch(op)
 {
 case 'f':
  while(entry=readdir(dp))
  {
   if(entry->d_type==DT_REG)
    printf("%s\n",entry->d_name);
  }
  break;
 case 'n':
  while(entry=readdir(dp))
  {
   if(entry->d_type==DT_DIR) dc++;
   if(entry->d_type==DT_REG) fc++;
  }
 
  printf("%d Dir(s)\t%d File(s)\n",dc,fc);
  break;
 case 'i':
  while(entry=readdir(dp))
  {
   if(entry->d_type==DT_REG)
    printf("%s\t%d\n",entry->d_name,entry->d_fileno);
  }
 }

 closedir(dp);
}

int main()
{
 char buff[80],tok1[10],tok2[10],tok3[10],tok4[10];
 int pid,n;

 while(1)
 {
  printf("myshell$");
  fflush(stdin);
  fgets(buff,80,stdin);
  n = sscanf(buff,"%s %s %s %s",tok1,tok2,tok3,tok4);
  if(strcmp(tok1,"list")==0)
   list(tok3,tok2[0]);
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
