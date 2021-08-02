#include <stdio.h>
#include <stdlib.h>

void doc_matrix(FILE *fp, int a[][100], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            fscanf(fp, "%d", &a[i][j]);
        }
    }
    fprintf(fp, "\n");
}

FILE *fp;
const char *name = "C:/Trenlop10/cau15docfile/MA_TRAN.txt";

void doc_file_matrix(int a[][100], int b[][100], int *n, int *m)
{
    fp = fopen(name, "r");
    int n1, m1;
    if (fp != NULL)
    {
        fscanf(fp, "%d %d", &n1, &m1);

        doc_matrix(fp, a, n1, m1);
        doc_matrix(fp, b, n1, m1);

        *n = n1;
        *m = m1;
    }
}

void tong_matrix(int a[][100], int b[][100], int c[][100], int n, int m)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void in_matrix_file(int a[][100], int n, int m)
{
    fp = fopen(name, "a");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            fprintf(fp, "%d ", a[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
}

int main()
{
    int a[100][100], b[100][100], c[100][100];
    int n, m;
    int t;
    
    while (1)
    {
        printf("lua chon : ");
        scanf("%d", &t);
        if (t < 0 || t > 3)
        {
            printf("lua chon lai \n");
        }
        else
        {
            switch (t)
            {
            case 1:
                doc_file_matrix(a, b, &n, &m);
                break;
            case 2:
                tong_matrix(a, b, c, n, m);
                in_matrix_file(c, n, m);
                break;
            }
            if (t == 3)
            {
                printf("finish");
                break;
            }
        }
    }
    return 0;
}