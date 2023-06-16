#include <stdio.h>
int main()
{
    int n;
    scanf(" %d ", &n);
    int largest = n;
    for (int i = 0; i < 4; i++)
    {
        int temp = n;
        temp = temp - (temp % 10);
        largest = largest > temp ? largest : temp;
        n = n / 10;
    }
    printf(" %d ", largest);
    return 0;
}