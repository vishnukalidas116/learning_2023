#include <stdio.h>
 
int main()
{
    int a[] = {0x1, 0xF4, 0x10001};
    int n = sizeof(a) / sizeof(a[0]);
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += countSetBits(a[i]);
    }
    printf("Total number of set bits is %d\n", count);
    return 0;
}
 
int countSetBits(int n)
{
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}