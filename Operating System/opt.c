#include <stdio.h>
#define MAX 20

int frames[MAX], ref[MAX], faults = 0, sp = 0, m, n;

void accept() {
    printf("Enter number of frames & references: ");
    scanf("%d %d", &n, &m);
    printf("Enter reference string: ");
    for (int i = 0; i < m; i++) scanf("%d", &ref[i]);
}

void disp() {
    printf("\nTotal Page Faults: %d\n", faults);
}

int search(int pno) {
    for (int i = 0; i < n; i++) 
        if (frames[i] == pno) return i;
    return -1;
}

int get_optimal(int start) {
    int replace_index = -1, farthest = start;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = start; j < m && frames[i] != ref[j]; j++);
        if (j == m) return i; // Not used again, replace immediately
        if (j > farthest) farthest = j, replace_index = i;
    }
    return replace_index;
}

void optimal() {
    for (int i = 0; i < n; i++) frames[i] = -1;
    for (int i = 0; i < m; i++) {
        int k = search(ref[i]);
        if (k == -1) {
            frames[(sp < n) ? sp++ : get_optimal(i + 1)] = ref[i];
            faults++;
        }
    }
}

int main() {
    accept();
    optimal();
    disp();
    return 0;
}
