#include <stdio.h>
#include <stdlib.h>
#define max_size 55

void ma_tran_xoay(int a[][max_size], int n,int m)
{
    int i, j;
    int hang = n - 1;
    int cot = m - 1;
    int vong = 0;
    int value = 1;

    while (value <= n * m)
    {
        //hang tren cung
        for (i = vong; i <= cot && value <= n * m; i++)
        {
            a[vong][i] = value++;
        }
        //cot ngoai cung ben phai
        for (j = vong + 1; j <= hang && value <= n * m; j++)
        {
            a[j][cot] = value++;
        }
        //hang cuoi cung
        for (i = cot - 1; i >= vong && value <= n * m; i--)
        {
            a[hang][i] = value++;
        }
        //cot ngoai cung ben trai
        for (j = hang - 1; j >= vong + 1 && value <= n * m; j--)
        {
            a[j][vong] = value++;
        }

        hang--;
        cot--;
        vong++;
    }
    printf("tao ma tran xoay thanh cong\n");
}

void in_matrix(int a[][max_size], int n,int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%02d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[max_size][max_size];
    int n, m,t;
    while (1)
    {
        printf("lua chon : ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("kich thuoc nxm = ");
            scanf("%d %d", &n,&m);
            break;
        case 2:
            ma_tran_xoay(a, n,m);
            break;
        case 3:
            in_matrix(a, n,m);
            break;
        }
        if (t == 4)
        {
            printf("ket thuc.");
            break;
        }
    }

    return 0;
}