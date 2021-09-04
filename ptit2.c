#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int check(unsigned long long a)
{
    int temp;
    temp = a % 10;
    int r;
    a = a / 10;
    while (a > 0)
    {
        r = a % 10;
        printf("%d",r);
        if (abs(r - temp) != 1)
        {
            return 0;
        }
        temp = r;
        a = a / 10;
    }
    return 1;
}

int main()
{
    int t;
    unsigned long long a;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%llu", &a);
        if (check(a) == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}