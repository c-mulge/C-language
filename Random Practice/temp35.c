//krishna

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char fname[50];
    int bno;
    struct node *next;
} *ptr, *temp, *first = NULL;

struct table {
    char fname[50];
    int start, length, end;
} t[30];

int d, used, frees, i, j, k = 0;

void userinput() {
    printf("Enter disk size: ");
    scanf("%d", &d);
    used = 0;
    frees = d;
    for (i = 0; i < d; i++) {
        ptr = (struct node *)malloc(sizeof(struct node));
        strcpy(ptr->fname, "");
        ptr->bno = i;
        ptr->next = NULL;
        if (first == NULL)
            temp = first = ptr;
        else {
            temp->next = ptr;
            temp = temp->next;
        }
    }
}

int checkspace(int size) {
    int c, no;
    temp = first;
    while (temp) {
        while (!(strcmp(temp->fname, "") == 0) && temp->next != NULL)
            temp = temp->next;
        no = temp->bno;
        c = 0;
        struct node *check = temp;
        while (check != NULL && strcmp(check->fname, "") == 0) {
            c++;
            if (c >= size)
                return no;
            check = check->next;
        }
        temp = temp->next;
    }
    return -1;
}

void allocate() {
    printf("\nEnter file name: ");
    scanf("%s", t[k].fname);
    printf("\nEnter file size: ");
    scanf("%d", &t[k].length);
    j = checkspace(t[k].length);
    if (j != -1) {
        t[k].start = j;
        frees -= t[k].length;
        used += t[k].length;
        temp = first;
        while (temp->bno != j)
            temp = temp->next;
        for (i = 0; i < t[k].length && temp != NULL; i++) {
            strcpy(temp->fname, t[k].fname);
            temp = temp->next;
        }
        t[k].end = j + t[k].length - 1;
        k++;
    } else {
        printf("No space available\n");
    }
}

void removeentry(char *s) {
    for (i = 0; i < k; i++) {
        if (strcmp(t[i].fname, s) == 0) {
            while (i < k - 1) {
                t[i] = t[i + 1];
                i++;
            }
            k--;
            return;
        }
    }
}

void deallocate() {
    char s[50];
    printf("Enter filename: ");
    scanf("%s", s);
    for (i = 0; i < k; i++) {
        if (strcmp(t[i].fname, s) == 0) {
            frees += t[i].length;
            used -= t[i].length;
            break;
        }
    }
    temp = first;
    while (temp) {
        if (strcmp(temp->fname, s) == 0)
            strcpy(temp->fname, "");
        temp = temp->next;
    }
    removeentry(s);
}

void showspace() {
    printf("Free space: %d\n", frees);
    printf("Used space: %d\n", used);
}

int main() {
    int ch;
    userinput();

    while (1) {
        printf("\n1: Allocate\n2: Deallocate\n3: Show Space\n4: Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                allocate();
                break;
            case 2:
                deallocate();
                break;
            case 3:
                showspace();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
