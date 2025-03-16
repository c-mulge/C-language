//My code

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
    int start, length, index[30];
} t[30];

int d, used, frees, i, j, cnt, k = 0;

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
        while (temp && strcmp(temp->fname, "") != 0)  
            temp = temp->next;  

        if (!temp) return -1;  

        no = temp->bno;
        c = 0;
        struct node *tptr = temp;

        while (tptr && c < size) {
            if (strcmp(tptr->fname, "") == 0)
                c++;
            else
                break;
            tptr = tptr->next;
        }
        
        if (c >= size)
            return no;
        
        temp = tptr;
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
        cnt = 0;
        t[k].start = j;
        frees -= t[k].length;
        used += t[k].length;
        
        temp = first;
        while (temp->bno != j) 
            temp = temp->next;
        
        i = 0;
        while (i < t[k].length && temp != NULL) {
            if (strcmp(temp->fname, "") == 0) {
                t[k].index[cnt++] = temp->bno;
                strcpy(temp->fname, t[k].fname);
                i++;
            }
            temp = temp->next;
        }
        k++;
    } else {
        printf("No space available\n");
    }
}

void removeentry(char *s) {
    for (i = 0; i < k; i++) {
        if (strcmp(t[i].fname, s) == 0) {
            for (int j = i; j < k - 1; j++)
                t[j] = t[j + 1];
            k--;
            return;
        }
    }
}

void deallocate() {
    char s[50];
    printf("Enter filename: ");
    scanf("%s", s);

    int fileFound = 0;
    for (i = 0; i < k; i++) {
        if (strcmp(t[i].fname, s) == 0) {
            frees += t[i].length;
            used -= t[i].length;
            fileFound = 1;
            break;
        }
    }

    if (!fileFound) {
        printf("File not found.\n");
        return;
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
        printf("\n1: Allocate\n2: Deallocate\n3: Show space\n4: Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: allocate(); break;
            case 2: deallocate(); break;
            case 3: showspace(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
