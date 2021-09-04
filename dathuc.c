#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void nhap_mang(int n, int a[])
{
    for (int i = n; i >= 0; i--)
    {
        printf("x ^ %d = ", i);
        scanf("%d", &a[i]);
    }
}
void in_phuong_trinh(char s, int n, int a[])
{
    printf("%c = ", s);
    for (int i = n; i >= 0; i--)
    {
        if (i != 0)
        {
            printf("%d*x^%d + ", a[i], i);
        }
        else
        {
            printf("%d", a[i]);
        }
    }
    printf("\n");
}
void tong(int x, int n, int a[])
{
    long long tong = 0;
    for (int i = n; i >= 0; i--)
    {
        tong = tong + a[i] * pow(x, i);
    }
    printf("tai x = %d thi phuong trinh co tong %lld\n", x, tong);
}
int cong_hai_da_thuc(char s, int n, int a[], int m, int b[], int c[])
{
    int i;
    if (n > m)
    {
        for (i = n; i >= 0; i--)
        {
            if (i > m)
            {
                c[i] = a[i];
            }
            else
            {
                c[i] = a[i] + b[i];
            }
        }
        in_phuong_trinh(s + 2, n, c);
        return n;
    }
    else if (m > n)
    {
        for (i = m; i >= 0; i--)
        {
            if (i > n)
            {
                c[i] = b[i];
            }
            else
            {
                c[i] = a[i] + b[i];
            }
        }
        in_phuong_trinh(s + 2, m, c);
        return m;
    }
    else
    {
        for (i = m; i >= 0; i--)
        {
            c[i] = a[i] + b[i];
        }
        in_phuong_trinh(s + 2, m, c);
        return m;
    }
}
int main()
{
    int a[100], b[100], c[100];
    int n, m;
    char s = 'A';
    printf("phuong 1 trinh co bac la :");
    scanf("%d", &n);
    printf("nhap he so cua phuong trinh :\n");
    nhap_mang(n, a);

    printf("phuong 2 trinh co bac la :");
    scanf("%d", &m);
    printf("nhap he so cua phuong trinh :\n");
    nhap_mang(m, b);

    in_phuong_trinh(s, n, a);
    in_phuong_trinh(s + 1, m, b);

    int x, k;
    k = cong_hai_da_thuc(s, n, a, m, b, c);
    printf("nhap x : ");
    scanf("%d", &x);
    tong(x,k,c);
    return 0;
}