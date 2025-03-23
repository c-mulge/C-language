#include <stdio.h>
#define MAX 20

int frames[MAX], ref[MAX], faults = 0, sp = 0, n, m;

void accept() {
    printf("Enter no. of frames & references: ");
    scanf("%d %d", &n, &m);
    
    printf("Enter reference string:\n");
    for (int i = 0; i < m; i++) {
        printf("[%d] = ", i);
        scanf("%d", &ref[i]);
    }
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

void fifo() {
    for (int i = 0; i < m; i++) 
        if (search(ref[i]) == -1) {
            frames[sp] = ref[i];
            sp = (sp + 1) % n;
            faults++;
        }
}

int main() {
    accept();
    fifo();
    disp();
    return 0;
}
