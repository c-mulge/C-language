#include <stdio.h>
#include <ctype.h>
/*
int main()
{
    char footballer[40];
    puts("Enter name");
    gets(footballer);
    puts("Happy footballing!");
    puts(footballer);
    return 0;
}*/

/*int main()
{
    char ch[30];
    printf("\nType any thing: ");
    while (1)
    {
        getchar(ch);
        printf("You typed: ");
        putchar(ch);
    }
    return 0;
}*/

/*int main()
{
    char ch;
    ch = getchar();
    if (islower(ch))
        putchar(toupper(ch));
    else
        putchar(tolower(ch));

    return 0;
}*/

int main()
{
    /*char str[] = "Life is like that";
    printf("%4s\n", str);*/
    FILE *fp;
    char ch;
    fp = fopen("temp1.c", "r");
    while (1)
    {
        ch = fgetc(fp);
        if (ch == EOF)
            break;
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);
    return 0;
}