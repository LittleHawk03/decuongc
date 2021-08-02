#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, r;
    int a2, b2,ucln;
    scanf("%d %d", &a, &b);
    a2 = a;
    b2 = b;
    while (b2 > 0)
    {
        r = a2 % b2;
        a2 = b2;
        b2 = r;
    }
    ucln = a / a2;
    ucln = ucln*b;
    printf("%d",ucln);
    return 0;
}