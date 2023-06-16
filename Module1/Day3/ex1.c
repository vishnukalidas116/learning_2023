#include <stdio.h>
void print_1_to_n(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}
void print_spaces(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("   ");
    }
}
void print_n_to_1(int n)
{
    for (int i = n; i >= 1; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
}
int main()
{
    int n;
    scanf(" %d ", &n);
    print_1_to_n(n);
    print_spaces(n);
    print_n_to_1(n);
    return 0;
}