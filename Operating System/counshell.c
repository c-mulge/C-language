#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

void count(const char *fn, char op) {
    int fh = open(fn, O_RDONLY), cc = 0, wc = 0, lc = 0;
    if (fh == -1) {
        printf("File %s not found.\n", fn);
        return;
    }

    char c, prev = ' ';
    while (read(fh, &c, 1) > 0) {
        cc++;
        if (c == '\n') lc++;
        if ((c == ' ' || c == '\n') && prev != ' ' && prev != '\n') wc++;
        prev = c;
    }

    close(fh);
    if (op == 'c') printf("Characters: %d\n", cc);
    else if (op == 'w') printf("Words: %d\n", wc);
    else if (op == 'l') printf("Lines: %d\n", lc);
}

int main(int argc,char*args[])
{
 char buff[80],tok1[10],tok2[10],tok3[10],tok4[10];
 int pid,n;

 while(1){

  printf("myshell$");
  fflush(stdin);
  fgets(buff,80,stdin);
  n = sscanf(buff,"%s %s %s",tok1,tok2,tok3);

  if(strcmp(tok1,"count")==0)  count(tok3,tok2[0]);
  else{
   pid = fork();

   if(pid>0)  wait(NULL);
   else{
        if(n==1)    execlp(tok1,tok1,NULL);
        if(n==2)    execlp(tok1,tok1,tok2,NULL);
        if(n==3)    execlp(tok1,tok1,tok2,tok3,NULL);
    }
  }
 }
 return 0;
}
