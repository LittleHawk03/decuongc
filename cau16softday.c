#include <stdio.h>
#include <stdlib.h>

void nhap_mang(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");
}

void ghep_mang(int n, int a[], int m, int b[], int c[])
{
    int i = 0, j = 0;
    int k = 0;
    while (i < n || j < m)
    {
        if (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                c[k] = a[i];
                k++;
                i++;
            }
            else
            {
                c[k] = b[j];
                k++;
                j++;
            }
        }
        else
        {
            if (n > m)
            {
                c[k] = a[i];
                k++;
                i++;
            }
            else
            {
                c[k] = b[j];
                k++;
                j++;
            }
        }
    }

    printf("ghep day thanh cong\n");
}

void in_mang(int a[], int k)
{
    int i;
    for (i = 0; i < k; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[100], b[100], c[100];
    int n, m, t, k;
    while (1)
    {
        printf("lua chon : ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("so luong phan tu day 1 : ");
            scanf("%d", &n);
            printf("nhap so luong phan tu day. \n");
            nhap_mang(a, n);
            printf("so luong phan tu day 2 : ");
            scanf("%d", &m);
            printf("nhap so luong phan tu day. \n");
            nhap_mang(b, m);
            break;
        case 2:
            ghep_mang(n, a, m, b, c);
            break;
        case 3:
            printf("day 1 : ");
            in_mang(a, n);
            printf("day 2 : ");
            in_mang(b, m);
            printf("day da ghep : ");
            in_mang(c, m + n);
            break;
        }
        if (t == 4)
        {
            printf("ket thuc truong trinh.");
            break;
        }
        
    }
    return 0;
}