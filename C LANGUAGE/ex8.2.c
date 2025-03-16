#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int a, b, c;
    int min, max, sum;
    float avg;
    if (argc != 4) {
        printf("Error: Invalid number of arguments\n");
        return 1;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
    min = a;
    max = a;
    sum = a + b + c;
    
    if (b < min) 
    {
        min = b;
    }
    if (c < min) 
    {
        min = c;
    }

    if (b > max) {
        max = b;
    }
    if (c > max) 
    {
        max = c;
    }

    avg = (float) sum / 3;

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Average: %.2f\n", avg);

    return 0;
}