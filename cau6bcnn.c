#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, r;
    int a2, b2, bcnn;
    scanf("%d %d", &a, &b);
    a2 = a;
    b2 = b;
    while (b2 > 0)
    {
        r = a2 % b2;
        a2 = b2;
        b2 = r;
    }
    printf("ucln = %d\n", a2);
    bcnn = a / a2;
    bcnn = bcnn * b;
    printf("bcnn = %d", bcnn);
    return 0;
}