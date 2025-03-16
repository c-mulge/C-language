#include<stdio.h>
int main(){
    FILE *fp;
    char ch;
    int nol=0,not=0,nob=0,noc=0;
    fp=fopen("pr1.c","r");
    while(1){
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        noc++;
        if(ch==' ')
            nob++;
        if(ch=='\n')
            nol++;
        if(ch=='\t')
            not++;
    }fclose(fp);
    printf("Noc: %d\nNob: %d\nNot: %d\nNol: %d",noc,nob,not,nol);
    return 0;
}