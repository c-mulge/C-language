#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = value;
    temp->next = NULL;
    return temp;
}

void freenode(struct node **h)
{
    free(*h);
    *h = NULL;
}

void initlist(struct node **h)
{
    (*h) = getnode(0);
}

void append(struct node *h, int value)
{
    struct node *temp = getnode(value);
    struct node *p = h;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    h->info++;
}

void display(struct node *h)
{
    struct node *p = h->next;
    while (p)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

void insert(struct node *h, int value, int pos)
{
    if (pos > h->info + 1)
    {
        printf("Invalid position.\n");
        exit(1);
    }
    struct node *temp = getnode(value);
    struct node *p = h;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
    h->info++;
}

void delete(struct node *h, int pos)
{
    if (pos > h->info || pos <= 0)
    {
        printf("Invalid position.\n");
        exit(1);
    }
    struct node *p = h;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    struct node *temp = p->next;
    p->next = temp->next;
    freenode(&temp);
    h->info--;
}

int search(struct node *h, int value)
{
    struct node *p = h->next;
    int pos = 1;
    while (p != NULL)
    {
        if (p->info == value)
        {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

void free_list(struct node *head)
{
    struct node *current = head;
    struct node *next;
    while (current != NULL)
    {
        next = current->next;
        freenode(&current);
        current = next;
    }
}

int main()
{
    int num, pos, value, d;
    struct node *list = NULL;
    initlist(&list);
    int choice;
    while (1)
    {
        printf("\nLinked List Operations: \n");
        printf("1. Append Linked List\n");
        printf("2. Add elements in Linked List\n");
        printf("3. Delete elements in Linked List\n");
        printf("4. Display Linked List\n");
        printf("5. Search in Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &num);
            append(list, num);
            break;
        case 2:
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(list, value, pos);
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &d);
            delete (list, d);
            break;
        case 4:
            printf("The linked list: \n");
            display(list);
            break;
        case 5:
            printf("Enter value to search: ");
            scanf("%d", &value);
            pos = search(list, value);
            if (pos != -1)
                printf("Value %d found at position %d\n", value, pos);
            else
                printf("Value %d not found in the list\n", value);
            break;
        case 6:
            free_list(list);
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}