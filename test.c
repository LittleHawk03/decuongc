#include <stdio.h>
int chuso(int d)
{
    int temp;
    do
    {
        temp = d % 10;
        d /= 10;
    } while (d > 0);
    return temp;
}
int dem(int d)
{
    int temp, j = 0;
    do
    {
        temp = d % 10;
        d /= 10;
        j++;
    } while (d > 0);
    return j;
}
int dao_nguoc(int n)
{
    int tmp;
    int res = 0;
    while (n > 0)
    {
        tmp = n % 10;
        res = res * 10 + tmp;
        n = n / 10;
    }

    return res;
}
int main()
{
    int d;
    scanf("%d", &d);
    int j = chuso(d);
    printf("%d ", j);
    int z =em(d);
    d = dao_nguoc(d);
    int s = dem(d);
    if (z == s)
    {
        int i = chuso(d);
        printf("%d", i);
    }
    else
    {
        printf("%d",0);
    }
    return 0;
}