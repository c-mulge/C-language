/*program to accept the character and check if its alphabet/digit/punct if alphabet then check
wheather its uppercase or lowercase, if yes then do their conversion respectively*/
#include<stdio.h>
int main()
{
    char ch;
    printf("Enter the Character= \n");
    scanf("%c",&ch);
    
    isalpha(ch) ?  printf("The Character is Alphabet\n") : printf("The Character is Numeric\n");
    //this is the ternary operator.
    //it is just to avoid use of if-else syntax.

return 0;
}