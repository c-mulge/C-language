//search f file.txt pattern
//search c file.txt pattern

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void search(const char *fn, char op, const char *pattern) {
    int fh = open(fn, O_RDONLY);
    if (fh == -1) {
        printf("File %s Not Found\n", fn);
        return;
    }

    char buff[255], c;
    int count = 0, i = 0, j = 0;
    while (read(fh, &c, 1)) {
        buff[j++] = c;
        if (c == '\n') {
            buff[j] = '\0', j = 0, i++;
            if (strstr(buff, pattern)) {
                printf("%d: %s", i, buff);
                if (op == 'f') break;
                if (op == 'c') count++;
            }
        }
    }

    if (op == 'c') printf("Total Occurrences = %d\n", count);
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