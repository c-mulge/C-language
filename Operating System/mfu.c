#include <stdio.h>
#define MAX 20

int frames[MAX], ref[MAX], mem[MAX][MAX], count[MAX], faults = 0, sp = 0, n, m;

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

    printf("\n\nPage Frames:\n");
    for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < m; j++) 
            printf("%3d", mem[i][j] ? mem[i][j] : 0);

    printf("\nTotal Page Faults: %d\n", faults);
}

int search(int pno) {
    for (int i = 0; i < n; i++)
        if (frames[i] == pno) return i;
    return -1;
}

int get_mfu() {
    int max_i = 0;
    for (int i = 1; i < n; i++)
        if (count[i] > count[max_i]) max_i = i;
    return max_i;
}

void mfu() {
    for (int i = 0; i < m; i++) {
        int k = search(ref[i]);
        if (k == -1) {
            sp = (sp < n) ? sp++ : get_mfu();
            frames[sp] = ref[i];
            count[sp] = 1;
            faults++;
        } else count[k]++;

        for (int j = 0; j < n; j++)
            mem[j][i] = frames[j];
    }
}

int main() {
    accept();
    mfu();
    disp();
    return 0;
}
