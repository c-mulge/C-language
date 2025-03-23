#include <stdio.h>
#define MAX 20

int frames[MAX], ref[MAX], time[MAX], faults = 0, sp = 0, n, m;

void accept() {
    printf("Enter no. of frames & references: ");
    scanf("%d %d", &n, &m);

    printf("Enter reference string:\n");
    for (int i = 0; i < m; i++) 
        scanf("%d", &ref[i]);
}

void disp() {
    printf("\nReference String:");
    for (int i = 0; i < m; i++) printf(" %d", ref[i]);
    printf("\nTotal Page Faults: %d\n", faults);
}

int search(int pno) {
    for (int i = 0; i < n; i++)
        if (frames[i] == pno) return i;
    return -1;
}

int get_lru() {
    int min_i = 0;
    for (int i = 1; i < n; i++)
        if (time[i] < time[min_i]) min_i = i;
    return min_i;
}

void lru() {
    for (int i = 0; i < m; i++) {
        int k = search(ref[i]);
        if (k == -1) {
            sp = (sp < n) ? sp++ : get_lru();
            frames[sp] = ref[i];
            faults++;
        } 
        time[sp] = i;
    }
}

int main() {
    accept();
    lru();
    disp();
    return 0;
}
