#include<stdio.h>
int main()
{
    int a,b;
    printf("enter first number:");
    scanf("%d",&a);
    printf("enter second number:");
    scanf("%d",&b);
    if(a>b)
    {
        printf("A is biggest number:%d",a);
    }
    else
    {
        printf("B is biggest number:%d",b);
    }
    return 0;
}

