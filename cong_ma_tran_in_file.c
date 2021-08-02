#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void lay_matrix(FILE *fp, int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &a[i][j]);
        }
        fscanf(fp, "\n");
    }
    fscanf(fp, "\n");
}
void in_matrix(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tong_matrix(int a[][100], int b[][100], int c[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void in_matrix_file(FILE *fp,int a[][100], int n, int m)
{
    
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
    int n, m, k;
    char s1[100], s2[100];
    const char *name = "C:/Trenlop10/cau15docfile/MA_TRAN.txt";
    FILE *fp, *fp2;
    printf("1.	Doc tep MA_TRAN.C\n2.	Ghi ma tran C bo sung vao cuoi tep tren \n3.	Ket thuc");

    while (1)
    {
        printf("\nlua chon cua ban la: ");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            fp = fopen(name, "r");
            if (fp != NULL)
            {

                fscanf(fp, "%d %d", &m, &n);
                printf("%d %d\n", m, n);
                fscanf(fp, "\n");
                fgets(s1, 20, fp);
                puts(s1);

                lay_matrix(fp, a, m, n);
                in_matrix(a, m, n);

                fscanf(fp, "\n");
                fgets(s2, 20, fp);
                puts(s2);
                lay_matrix(fp, b, m, n);
                in_matrix(b, m, n);
            }
            else
            {
                printf("file k ton tai");
            }
            break;
        case 2:
            fp2 = fopen(name,"a");
            tong_matrix(a,b,c,m,n);
            in_matrix(c,m,n);
            fputs("tong ma tran A + B :\n",fp2);
            in_matrix_file(fp2,c,m,n);
            break;
    
        }
        if (k == 3)
        {
            break;
        }
        
    }
}
