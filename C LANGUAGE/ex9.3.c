#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    FILE *src, *dest;
    int c;

    if (argc != 3) 
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "r");
    if (src == NULL) 
    {
        printf("Error: Unable to open source file\n");
        return 1;
    }

    dest = fopen(argv[2], "w");
    if (dest == NULL) 
    {
        printf("Error: Unable to open destination file\n");
        fclose(src);
        return 1;
    }

    while ((c = fgetc(src)) != EOF) 
    {
        if (isalpha(c)) 
        {
            if (isupper(c)) 
            {
                c = tolower(c);
            } else {
                c = toupper(c);
            }
        }
        fputc(c, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}