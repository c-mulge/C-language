#include <stdio.h>
#include <stdlib.h>

int calculateParityBits(int dataBits) {
    int m = 0;
    while ((1 << m) < (dataBits + m + 1))
        m++;
    return m;
}

void setParityBits(int *hammingCode, int dataBits, int parityBits, int evenParity) {
    for (int i = 0; i < parityBits; i++) {
        int parity = 0;
        for (int j = 0; j < dataBits + parityBits; j++) {
            if ((j + 1) & (1 << i)) {
                if (hammingCode[j] == 1) {
                    parity ^= 1;
                }
            }
        }
        if (evenParity) {
            hammingCode[(1 << i) - 1] = parity;
        } else {
            hammingCode[(1 << i) - 1] = 1 - parity;
        }
    }
}

void printHammingCode(int *hammingCode, int dataBits, int parityBits) {
    printf("Generated Hamming Code: ");
    for (int i = 0; i < dataBits + parityBits; i++) {
        printf("%d", hammingCode[i]);
    }
    printf("\n");
}

int main() {
    int dataBits, parityBits;
    
    printf("Enter the number of data bits: ");
    scanf("%d", &dataBits);

    parityBits = calculateParityBits(dataBits);
    
    int totalBits = dataBits + parityBits;
    int hammingCode[totalBits];
    
    printf("Enter the data bits (separated by spaces): ");
    for (int i = 0; i < dataBits; i++) {
        scanf("%1d", &hammingCode[i]);
    }
    
    int parityChoice;
    printf("Select parity type:\n");
    printf("1. Even Parity\n");
    printf("2. Odd Parity\n");
    printf("Enter your choice: ");
    scanf("%d", &parityChoice);
    
    int evenParity = 1;
    if (parityChoice == 2) {
        evenParity = 0;
    }
    
    setParityBits(hammingCode, dataBits, parityBits, evenParity);
    printHammingCode(hammingCode, totalBits, parityBits);
    
    return 0;
}
