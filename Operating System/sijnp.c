#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process_info {
    char pname[20];
    int at, bt, ct, bt1;
    struct process_info *next;
} NODE;

int n, time = 0;
NODE *first = NULL, *last = NULL;

void accept_info() {
    printf("Enter no.of process: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        NODE *p = (NODE *)malloc(sizeof(NODE));
        printf("Enter process name, arrival time, burst time: ");
        scanf("%s%d%d", p->pname, &p->at, &p->bt);
        p->bt1 = p->bt;
        p->next = NULL;
        if (!first) first = p;
        else last->next = p;
        last = p;
    }
}

void print_output() {
    float avg_tat = 0, avg_wt = 0;
    printf("\npname\tat\tbt\tct\ttat\twt\n");
    for (NODE *p = first; p; p = p->next) {
        int tat = p->ct - p->at, wt = tat - p->bt;
        avg_tat += tat, avg_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->ct, tat, wt);
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
                p->next = temp.next;
            }
}

NODE *get_sjf() {
    NODE *p = first, *min_p = NULL;
    int min = 9999;
    while (p) {
        if (p->at <= time && p->bt1 && p->bt1 < min) {
            min = p->bt1;
            min_p = p;
        }
        p = p->next;
    }
    return min_p;
}

void sjfnp() {
    int completed = 0;
    while (completed < n) {
        NODE *p = get_sjf();
        if (!p) time++;
        else {
            printf("\n%d___%s___%d", time, p->pname, time + p->bt1);
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
    sjfnp();
    print_output();
    return 0;
}
