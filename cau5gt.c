#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long x = 1;
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        x = x*i;
    }
    printf("%lld",x);
    return 0;
}