#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void nhao_he_so(int a[], int n,char s)
{
    int i;
    for (i = n; i >= 0; i--)
    {
        printf("%c[%d] = ",s,i);
        scanf("%d", &a[i]);
    }
    printf("\n");
}

void in_he_so(int a[], int n,char s)
{
    int i;
    for (i = n; i >= 0; i--)
    {
        printf(" %c[%d] = %d ",s, i, a[i]);
    }
    printf("\n");
}

void gia_tri_tai_x(int a[], int n, int x)
{
    int i;
    long tong = 0;
    for (i = n; i >= 0; i--)
    {
        tong = tong + a[i] * pow(x, i);
    }

    printf("gia tri cau da thuc tai x = %d la : %ld\n", x, tong);
}

int tong_P_Q(int n, int a[], int m, int b[], int c[])
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
        return n;
    }
    else
    {
        for (i = m; i >= 0; i--)
        {
            if (i > n)
            {
                c[i] = b[i];
            }
            else
            {
                c[i] = b[i] + a[i];
            }
        }
        return m;
    }
}

int main()
{
    int a[100], b[100], c[100];
    int n, m, t, k;
    int x;
    int flag = 0;
    while (1)
    {
        printf("lua chon : ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("bac cua da thuc 1 la : ");
            scanf("%d", &n);
            printf("nhap cac he so cua da thuc : \n");
            nhao_he_so(a, n,'a');
            printf("bac cua da thuc 2 la : ");
            scanf("%d", &m);
            printf("nhap cac he so cua da thuc : \n");
            nhao_he_so(b, m,'b');
            flag = 1;
            break;
        case 2:
            if (flag == 1)
            {
                k = tong_P_Q(n, a, m, b, c);
                in_he_so(c, k,'c');
                flag = 2;
            }
            else
            {
                printf("hay nhap lai hai da thuc\n");
            }
            break;
        case 3:
            if (flag = 2)
            {
                printf("he so da thuc 1 : ");
                in_he_so(a, n,'a');
                printf("he so da thuc 1 : ");
                in_he_so(b, m,'b');
                printf("he so da thuc 1 : ");
                in_he_so(c, k,'c');
                
            }
            else
            {
                printf("thuc hien yeu cau 2 truoc\n");
            }

            break;
        case 4:
            printf("x = ");
            scanf("%d", &x);

            gia_tri_tai_x(a, n, x);

            gia_tri_tai_x(b, m, x);

            gia_tri_tai_x(c, k, x);
            break;
        }
        if (t == 5)
        {
            break;
        }
    }

    return 0;
}