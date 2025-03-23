#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process {
    char pname[20];
    int at, bt, ct, bt1;
    struct process *next;
} NODE;

NODE *first = NULL, *last = NULL;
int n, time = 0;

void accept_info() {
    printf("Enter number of processes: ");
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
}

void sort() {
    for (NODE *p = first; p; p = p->next) {
        for (NODE *q = p->next; q; q = q->next) {
            if (p->at > q->at) { // Swap pointers instead of copying data
                char temp[20]; strcpy(temp, p->pname);
                strcpy(p->pname, q->pname); strcpy(q->pname, temp);
                int t = p->at; p->at = q->at; q->at = t;
                t = p->bt; p->bt = q->bt; q->bt = t;
                t = p->bt1; p->bt1 = q->bt1; q->bt1 = t;
            }
        }
    }
}

NODE *get_fcfs() {
    for (NODE *p = first; p; p = p->next)
        if (p->at <= time && p->bt1 > 0) return p;
    return NULL;
}

void fcfs() {
    int completed = 0;
    while (completed < n) {
        NODE *p = get_fcfs();
        if (!p) time++;
        else {
            printf("\n %d___%s___", time, p->pname);
            time += p->bt1;
            p->ct = time;
            printf("%d", p->ct);
            p->bt1 = 0;
            completed++;
        }
    }
}

void print_output() {
    float avg_tat = 0, avg_wt = 0;
    printf("\nPName\tAT\tBT\tCT\tTAT\tWT\n");
    
    for (NODE *p = first; p; p = p->next) {
        int tat = p->ct - p->at;
        int wt = tat - p->bt;
        avg_tat += tat;
        avg_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->ct, tat, wt);
    }
    
    printf("Avg TAT = %.2f, Avg WT = %.2f\n", avg_tat / n, avg_wt / n);
}

int main() {
    accept_info();
    sort();
    fcfs();
    print_output();
    return 0;
}
