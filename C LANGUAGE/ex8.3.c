#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    char *str = argv[1];
    char a = argv[2][0];
    char b = argv[3][0];

    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == a) 
        {
            str[i] = b;
        }
    }
    printf("Modified string: %s\n", str);
    return 0;
}