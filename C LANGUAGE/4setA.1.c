/*program to accept the character and check if its alphabet/digit/punct if alphabet then check
wheather its uppercase or lowercase, if yes then do their conversion respectively*/
#include<stdio.h>
int main()
{
    char ch;
    printf("Enter the Character= \n");
    scanf("%c",&ch);
    
    if(isalpha(ch))
    {
        printf("The Character is Alphabet.\n");
        if(isupper(ch))
        {
            printf("The Character is in Uppercase.\n");
            printf("Convert= E%c",ch=tolower(ch));
        }
        else
        { 
            printf("The Character is Lowercase.\n");
            printf("Convert= %c",ch=toupper(ch));
        }
    }
    
    else
    if(isdigit(ch))
    {
        printf("The Character is Digit.\n");
    }
    else
    if(ispunct(ch))
    {
        printf("The Character is Punctuation.\n");
    }

}