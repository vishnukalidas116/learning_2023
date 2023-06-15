#include <stdio.h>
int main()
{
    int a[3] = {0x1, 0xF4, 0x10001};
    int i, count = 0;
    for (i = 0; i < 3; i++) {
        while (a[i] != 0) {
            count++;
            a[i] = a[i] & (a[i] - 1);
        }
    }
    printf("The total number of set bits is: %d", count);
    return 0;
}