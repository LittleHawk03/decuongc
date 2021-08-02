#include <stdio.h>
#include <stdlib.h>
void nhap_mang(int a[][100], int x, int y)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
}

void in_matrix(int a[][100], int x, int y)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void tich_hai_ma_tran(int a[][100], int b[][100], int c[][100], int m, int p, int n)
{
    int i, j, k;
    int tmp;
    for (i = 0; i < m; i++)
    {
        for (k = 0; k < n; k++)
        {
            tmp = 0;
            for (j = 0; j < p; j++)
            {
                tmp = tmp + a[i][j] * b[j][k];
            }
            c[i][k] = tmp;
        }
    }
    printf("tinh tich ma tran thanh cong \n");
}

int main()
{
    int a[100][100], b[100][100], c[100][100];
    int m, n, p, t;
    int flag = 0;
    printf("1.	Nhap 2 ma tran  \n");
    printf("2.	Tinh tich 2 ma tran  \n");
    printf("3.	Hien thi 3 ma tran  \n");
    printf("4.	Ket thuc \n");
    while (1)
    {
        printf("lua chon : ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("nhap kich thuoc hai ma tran mxp va pxn voi m p n : ");
            scanf("%d %d %d", &m, &p, &n);
            nhap_mang(a, m, p);
            nhap_mang(b, p, n);
            flag = 1;
            break;
        case 2:
            if (flag == 1)
            {
                tich_hai_ma_tran(a, b, c, m, p, n);
                flag = 2;
            }
            else
            {
                printf("hay nhap A va B\n");
            }

            break;
        case 3:
            if (flag == 2)
            {
                printf("Ma tran A : \n");
                in_matrix(a, m, p);
                printf("Ma tran B : \n");
                in_matrix(b, p, n);
                printf("Ma tran AxB : \n");
                in_matrix(c, m, n);
            }
            else
            {
                printf("hay nhap 2 truoc\n");
            }
            
            break;
        }
        if (t == 4)
        {
            printf("chuong trinh thuc su ket thuc");
            break;
        }
    }

    return 0;
}