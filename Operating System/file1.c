#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char fname[50];
    int bno;
    struct node *next;
} *first = NULL, *temp;

struct table {
    char fname[50];
    int start, length, end;
} t[30];

int d, used = 0, frees, k = 0;

void userinput() {
    printf("Enter disk size: ");
    scanf("%d", &d);
    frees = d;

    for (int i = 0; i < d; i++) {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->fname[0] = '\0'; // Empty filename
        ptr->bno = i;
        ptr->next = NULL;

        if (!first)
            first = temp = ptr;
        else {
            temp->next = ptr;
            temp = ptr;
        }
    }
}

int checkspace(int size) {
    temp = first;
    while (temp) {
        if (temp->fname[0] == '\0') {
            struct node *check = temp;
            int count = 0, start = temp->bno;

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
    t[k].end = j + t[k].length - 1;
    frees -= t[k].length;
    used += t[k].length;

    temp = first;
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

            temp = first;
            while (temp) {
                if (strcmp(temp->fname, s) == 0)
                    temp->fname[0] = '\0'; // Mark as free
                temp = temp->next;
            }

            for (int j = i; j < k - 1; j++) 
                t[j] = t[j + 1]; // Shift entries

            k--;
            return;
        }
    }
    printf("File not found\n");
}

void showspace() {
    printf("Free space: %d\nUsed space: %d\n", frees, used);
}

int main() {
    int ch;
    userinput();

    while (1) {
        printf("\n1: Allocate\n2: Deallocate\n3: Show Space\n4: Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: allocate(); break;
            case 2: deallocate(); break;
            case 3: showspace(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
