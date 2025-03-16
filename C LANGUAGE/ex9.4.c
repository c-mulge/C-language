#include <stdio.h>
int main(int argc, char *argv[]) 
{
    FILE *fp;
    char ch;
    int words = 0, lines = 0, characters = 0;

    // Check if the filename is provided as a command line argument
    if (argc < 2) 
    {
        printf("Error: Filename not provided\n");
        return 1;
    }

    // Open the file for reading
    fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Read the file character by character and count the number of words, lines, and characters
    while ((ch = fgetc(fp)) != EOF) 
    {
        characters++;
        if (ch == '\n') 
        {
            lines++;
        }
        if (ch == ' ' || ch == '\n' || ch == '\t') 
        {
            words++;
        }
    }

    // Check if the last word is not counted
    if (characters > 0) 
    {
        words++;
        lines++;
    }

    // Close the file
    fclose(fp);

    // Print the number of words, lines, and characters
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);
    printf("Number of characters: %d\n", characters);

    return 0;
}
