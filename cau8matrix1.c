#include <stdio.h>
#include <stdlib.h>
void nhap_matrix(float a[][100], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    printf("\n");
}

void in_matrix(float a[][100], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.0f  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void min_and_max(float a[][100], int m, int n)
{
    int i, j;
    float MAX, MIN;
    MAX = a[0][0];
    MIN = a[0][0];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > MAX)
            {
                MAX = a[i][j];
            }
            if (a[i][j] < MIN)
            {
                MIN = a[i][j];
            }
        }
    }
    printf("MAX = %.0f\n", MAX);
    printf("MIN = %.0f\n", MIN);
}

int main()
{
    float a[100][100];
    int m, n;
    scanf("%d %d", &m, &n);
    nhap_matrix(a, m, n);
    in_matrix(a, m, n);
    min_and_max(a, m, n);
    return 0;
}