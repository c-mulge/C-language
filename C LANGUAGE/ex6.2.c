#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

char* copy_string(char*, char*);
char* concatenate_strings(char*, char*);
int compare_strings(char*, char*);

int main() {
    char str1[MAX_LEN], str2[MAX_LEN], *result_str;
    int a;

    
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    
    do {
        printf("\nString Operations Menu:\n");
        printf("1. Copy\n");
        printf("2. Concatenation\n");
        printf("3. Compare\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &a);

        
        switch (a) {
            case 1:
                result_str = copy_string(str1, str2);
                printf("Copied string: %s\n", result_str);
                free(result_str);
                break;
            case 2:
                result_str = concatenate_strings(str1, str2);
                printf("Concatenated string: %s\n", result_str);
                free(result_str);
                break;
            case 3:
                if (compare_strings(str1, str2) == 0) {
                    printf("Strings are equal.\n");
                } else {
                    printf("Strings are not equal.\n");
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid. Please select a valid option.\n");
        }
    } while (a != 4);

    return 0;
}

char* copy_string(char *src_str, char *dest_str) {
    char *result_str = (char*) malloc(strlen(src_str) + 1);
    strcpy(result_str, src_str);
    strcpy(dest_str, src_str);
    return result_str;
}


char* concatenate_strings(char *str1, char *str2) {
    char *result_str = (char*) malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result_str, str1);
    strcat(result_str, str2);
    return result_str;
}


int compare_strings(char *str1, char *str2) {
    return strcmp(str1, str2);
}
