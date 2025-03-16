#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch;

    // Open the file for reading
    fp = fopen("b.txt", "r");
    if (fp == NULL) 
    {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Read the file character by character and print each character with its case reversed
    while ((ch = fgetc(fp)) != EOF) 
    {
        if (isupper(ch)) {
            ch = tolower(ch);
        } else if (islower(ch)) {
            ch = toupper(ch);
        }
        putchar(ch);
    }

    // Close the file
    fclose(fp);

    return 0;
}
