#include <stdio.h>

void printBits(int num);

int main() {
    int num;
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);

    printBits(num);

    return 0;
}

void printBits(int num) {
    int i;
    unsigned int mask = 1 << 31; 

    for (i = 0; i < 32; i++) {
        
        int bit = (num & mask) != 0;
        printf("%d", bit);

        mask >>= 1;
    }

    printf("\n");
}