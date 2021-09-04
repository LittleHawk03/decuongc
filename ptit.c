#include <stdio.h>
#include <stdlib.h>
void nhap(int a[][100], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void check(int a[][100], int n)
{
    int i, j;
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        int temp = 0;
        for (j = 0; j < 3; j++)
        {
            temp = temp + a[i][j];
        }
        if (temp >= 2)
        {
            sum++;
        }
    }
    printf("%d", sum);
}

int main()
{
    int a[100][100];
    int n;
    scanf("%d", &n);
    nhap(a, n);
    check(a, n);
    return 0;
}