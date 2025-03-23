#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void typeline(const char *fn, const char *op) {
    int fh = open(fn, O_RDONLY);
    if (fh == -1) {
        printf("File %s not found.\n", fn);
        return;
    }

    char c;
    int i = 0, totalLines = 0, n = atoi(op);

    if (strcmp(op, "a") == 0) {
        while (read(fh, &c, 1) > 0) putchar(c);
    } else if (n > 0) {
        while (read(fh, &c, 1) > 0) {
            putchar(c);
            if (c == '\n' && ++i == n) break;
        }
    } else {
        while (read(fh, &c, 1) > 0) if (c == '\n') totalLines++;
        lseek(fh, 0, SEEK_SET);
        i = 0;
        while (read(fh, &c, 1) > 0) {
            if (c == '\n' && ++i == totalLines + n) break;
        }
        while (read(fh, &c, 1) > 0) putchar(c);
    }

    close(fh);
}

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
  if(strcmp(tok1,"typeline")==0)
   typeline(tok2,tok3);
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
