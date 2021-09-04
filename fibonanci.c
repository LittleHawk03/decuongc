#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[100];
    int n,i;
    printf("nhap vi tri cua so : ");
    scanf("%d",&n);
    a[0] = 0;
    a[1] = 1;
    for ( i = 2; i <= n; i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
    printf("%d",a[n]);
    return 0;
}