#include <stdio.h>
int main()
{
    int n;
    scanf(" %d ", &n);
    if (n < 1)
    {
        printf(" Not Valid ");
        return 0;
    }
    int smallest = 9, largest = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf(" %d ", &num);
        if (num < smallest)
        {
            smallest = num;
        }
        if (num > largest)
        {
            largest = num;
        }
    }
    printf(" %d ", smallest);
    printf(" %d ", largest);
    return 0;
}