#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

void count(char *fn,char op){
    int fh=open(fn,O_RDONLY),wc=0,lc=0,cc=0;
    if(fh==-1){
        printf("File %s not found.\n",fn); return;
    }
    char c,prev=' ';
    while(read(fh,&c,1)>0){
        cc++;
        if(c=='\n') lc++;
        if((c==' '||c=='\n')&&prev!=' '&& prev!='\n') wc++;
        prev=c;
    }
    close(fh);
    if(op=='c') printf("Character: %d\n",cc);
    else if(op=='w') printf("Words: %d\n",wc);
    else if(op=='l') printf("Lines: %d\n",lc);
}

