#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int stringLength(char *str);
char* stringReverse(char *str);
char* stringToUpper(char *str);
char* stringToLower(char *str);

int main() {
    char str[100], a;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    do {
        printf("\nSelect the Options:\n");
        printf("1. Find length of the string\n");
        printf("2. Reverse the string\n");
        printf("3. Convert string to uppercase\n");
        printf("4. Convert string to lowercase\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %c", &a);

        switch(a) {
            case '1': {
                int len = stringLength(str);
                printf("Length of the string: %d\n", len);
                break;
            }
            case '2': {
                char* reversedStr = stringReverse(str);
                printf("Reversed string: %s\n", reversedStr);
                free(reversedStr);
                break;
            }
            case '3': {
                char* upperStr = stringToUpper(str);
                printf("Uppercase string: %s\n", upperStr);
                free(upperStr);
                break;
            }
            case '4': {
                char* lowerStr = stringToLower(str);
                printf("Lowercase string: %s\n", lowerStr);
                free(lowerStr);
                break;
            }
            case '5': {
                
                break;
            }
            default: {
                printf("Invalid. Please select correct option\n");
                break;
            }
        }
    } while (a != '5');

    return 0;
}

int stringLength(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

char* stringReverse(char *str) {
    int len = stringLength(str);
    char* reversedStr = (char*) malloc((len + 1) * sizeof(char));
    reversedStr[len] = '\0';

    for (int i = 0; i < len; i++) {
        reversedStr[i] = *(str + len - 1 - i);
    }

    return reversedStr;
}

char* stringToUpper(char *str) {
    int len = stringLength(str);
    char* upperStr = (char*) malloc((len + 1) * sizeof(char));
    upperStr[len] = '\0';

    for (int i = 0; i < len; i++) {
        upperStr[i] = toupper(*(str + i));
    }

    return upperStr;
}

char* stringToLower(char *str) {
    int len = stringLength(str);
    char* lowerStr = (char*) malloc((len + 1) * sizeof(char));
    lowerStr[len] = '\0';

    for (int i = 0; i < len; i++) {
        lowerStr[i] = tolower(*(str + i));
    }

    return lowerStr;
}
