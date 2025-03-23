#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process_info {
    char pname[20];
    int at, bt, ct, bt1;
    struct process_info *next;
} NODE;

NODE *first = NULL, *last = NULL;
int n, ts, time = 0;

void accept_info() {
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        NODE *p = (NODE *)malloc(sizeof(NODE));
        printf("Enter process name, arrival time, burst time: ");
        scanf("%s %d %d", p->pname, &p->at, &p->bt);
        p->bt1 = p->bt;
        p->next = NULL;
        if (!first) first = p;
        else last->next = p;
        last = p;
    }
    printf("Enter time slice: ");
    scanf("%d", &ts);
}

void print_output() {
    float avg_tat = 0, avg_wt = 0;
    printf("\npname\tat\tbt\tct\ttat\twt\n");
    for (NODE *p = first; p; p = p->next) {
        int tat = p->ct - p->at, wt = tat - p->bt;
        avg_tat += tat;
        avg_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->ct, tat, wt);
    }
    printf("Avg TAT=%.2f\tAvg WT=%.2f\n", avg_tat / n, avg_wt / n);
}

void sort() {
    for (NODE *p = first; p && p->next; p = p->next)
        for (NODE *q = p->next; q; q = q->next)
            if (p->at > q->at) {
                NODE temp = *p; *p = *q; *q = temp;
                q->next = p->next; p->next = q;
            }
}

NODE *delq() {
    NODE *t = first;
    first = first->next;
    t->next = NULL;
    return t;
}

void addq(NODE *t) {
    last->next = t;
    last = t;
}

int is_arrived() {
    for (NODE *p = first; p; p = p->next)
        if (p->at <= time && p->bt1 != 0) return 1;
    return 0;
}

void rr() {
    int completed = 0;
    while (completed < n) {
        if (!is_arrived()) time++;
        else {
            NODE *p = first;
            while (p->at > time || p->bt1 == 0) {
                addq(delq());
                p = first;
            }
            time += (p->bt1 <= ts) ? p->bt1 : ts;
            p->bt1 -= (p->bt1 <= ts) ? p->bt1 : ts;
            p->ct = time;
            if (p->bt1 == 0) completed++;
            addq(delq());
        }
    }
}

int main() {
    accept_info();
    sort();
    rr();
    print_output();
    return 0;
}
