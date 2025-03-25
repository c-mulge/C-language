#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process {
    char pname[20];
    int at, bt, ct, bt1, p;
    struct process *next;
} NODE;

NODE *first = NULL, *last = NULL;
int n, time = 0;

void accept_info() {
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        NODE *p = (NODE *)malloc(sizeof(NODE));
        printf("Enter process name, arrival time, burst time, priority: ");
        scanf("%s %d %d %d", p->pname, &p->at, &p->bt, &p->p);
        p->bt1 = p->bt;
        p->next = NULL;

        if (!first) first = p;
        else last->next = p;
        last = p;
    }
}

void print_output() {
    float avg_tat = 0, avg_wt = 0;
    printf("\npname\tat\tbt\tp\tct\ttat\twt\n");

    for (NODE *p = first; p; p = p->next) {
        int tat = p->ct - p->at, wt = tat - p->bt;
        avg_tat += tat;
        avg_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->p, p->ct, tat, wt);
    }

    printf("Avg TAT=%.2f\tAvg WT=%.2f\n", avg_tat / n, avg_wt / n);
}

void sort() {
    for (NODE *p = first; p && p->next; p = p->next)
        for (NODE *q = p->next; q; q = q->next)
            if (p->at > q->at) {
                NODE temp = *p; 
                *p = *q; 
                *q = temp;
                q->next = p->next;
                p->next = q;
            }
}

NODE *get_highest_priority() {
    NODE *p = first, *min_p = NULL;
    int min = 9999;

    while (p) {
        if (p->at <= time && p->bt1 > 0 && p->p < min) {
            min = p->p;
            min_p = p;
        }
        p = p->next;
    }

    return min_p;
}

void priority_scheduling() {
    int completed = 0;

    while (completed < n) {
        NODE *p = get_highest_priority();

        if (!p) time++;
        else {
            time += p->bt1;
            p->ct = time;
            p->bt1 = 0;
            completed++;
        }
        sort();
    }
}

int main() {
    accept_info();
    sort();
    priority_scheduling();
    print_output();
    return 0;
}
