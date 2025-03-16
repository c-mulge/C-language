//myshell$ count c a.txt
//myshell$ count w a.txt
//myshell$ count l a.txt




#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void count(char *fn, char op)
{
    int fh, cc = 0, wc = 0, lc = 0; // Initialize file descriptor and counters for characters, words, and lines
    char c; // Variable to store each character read from the file

    fh = open(fn, O_RDONLY); // Open the file in read-only mode
    if (fh == -1) // Check if the file was opened successfully
    {
        printf("File %s not found.\n", fn); // Print an error message if the file is not found
        return; // Exit the function
    }

    while (read(fh, &c, 1) > 0) // Read one character at a time from the file
    {
        if (c == ' ') // If the character is a space, increment the word count
            wc++;
        else if (c == '\n') // If the character is a newline, increment the word and line counts
        {
            wc++;
            lc++;
        }
        cc++; // Increment the character count
    }

    close(fh); // Close the file

    switch(op)
    {
    case 'c':
        printf("No.of characters:%d\n",cc);
        break;
    case 'w':
        printf("No.of words:%d\n",wc);
        break;
    case 'l':
        printf("No.of lines:%d\n",lc);
        break;
    }
}

int main(int argc,char*args[])
{
 char buff[80],tok1[10],tok2[10],tok3[10],tok4[10];
 int pid,n;

 while(1)
 {
  printf("myshell$");
  fflush(stdin);
  fgets(buff,80,stdin);
  n = sscanf(buff,"%s %s %s",tok1,tok2,tok3);
  if(strcmp(tok1,"count")==0)
   count(tok3,tok2[0]);
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
