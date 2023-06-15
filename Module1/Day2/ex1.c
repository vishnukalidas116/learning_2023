#include <stdio.h>
int main() {
    double x = 0.7;
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long exponent = *ptr >> 52;
    printf("Exponent in hexadecimal: 0x%llx\n", exponent);
    printf("Exponent in binary: 0b%llx\n", exponent);
    return 0;
}