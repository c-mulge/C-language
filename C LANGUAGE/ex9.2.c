#include <stdio.h>

int main(int argc, char *argv[]) 
{
    FILE *fp;
    long int size;

    if (argc != 2) 
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) 
    {
        printf("Error: Unable to open file\n");
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fclose(fp);

    printf("Size of file %s is %ld bytes\n", argv[1], size);

    return 0;
}