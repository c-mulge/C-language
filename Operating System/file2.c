#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char fname[50];
    int bno;
    struct node *next;
} *first = NULL;

struct table {
    char fname[50];
    int start, length;
} t[30];

int d, used = 0, frees, k = 0;

void userinput() {
    printf("Enter disk size: ");
    scanf("%d", &d);
    frees = d;
    
    struct node *temp = NULL;
    for (int i = 0; i < d; i++) {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->fname[0] = '\0';
        ptr->bno = i;
        ptr->next = NULL;
        
        if (!first) first = temp = ptr;
        else temp = temp->next = ptr;
    }
}

int checkspace(int size) {
    struct node *temp = first;
    while (temp) {
        if (temp->fname[0] == '\0') {
            int start = temp->bno, count = 0;
            struct node *check = temp;
            while (check && check->fname[0] == '\0') {
                if (++count >= size) return start;
                check = check->next;
            }
        }
        temp = temp->next;
    }
    return -1;
}

void allocate() {
    printf("Enter file name: ");
    scanf("%s", t[k].fname);
    printf("Enter file size: ");
    scanf("%d", &t[k].length);
    
    int j = checkspace(t[k].length);
    if (j == -1) {
        printf("No space available\n");
        return;
    }
    
    t[k].start = j;
    frees -= t[k].length;
    used += t[k].length;
    
    struct node *temp = first;
    while (temp->bno != j) temp = temp->next;
    for (int i = 0; i < t[k].length && temp; i++, temp = temp->next)
        strcpy(temp->fname, t[k].fname);
    
    k++;
}

void deallocate() {
    char s[50];
    printf("Enter filename: ");
    scanf("%s", s);
    
    for (int i = 0; i < k; i++) {
        if (strcmp(t[i].fname, s) == 0) {
            frees += t[i].length;
            used -= t[i].length;
            struct node *temp = first;
            while (temp) {
                if (strcmp(temp->fname, s) == 0) temp->fname[0] = '\0';
                temp = temp->next;
            }
            for (int j = i; j < k - 1; j++) t[j] = t[j + 1];
            k--;
            return;
        }
    }
    printf("File not found\n");
}

void showspace() {
    printf("\nFree space: %d\nUsed space: %d\n", frees, used);
}

int main() {
    int ch;
    userinput();
    
    while (1) {
        printf("\n1: Allocate\n2: Deallocate\n3: Show space\n4: Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: allocate(); break;
            case 2: deallocate(); break;
            case 3: showspace(); break;
            case 4: exit(0);
            default: printf("Invalid choice, try again.\n");
        }
    }
}
