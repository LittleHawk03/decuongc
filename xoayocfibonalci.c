#include <stdio.h>

void finbonanci(int b[], int n);
void botton_left(int x1, int x2, int y1, int y2, int a[][10], int b[], int d);
void top_right(int x1, int x2, int y1, int y2, int a[][10], int b[], int d);


void top_right(int x1, int x2, int y1, int y2, int a[][10], int b[], int d)
{
    int i;
    for (i = x1; i <= x2; i++)
    {
        a[y1][i] = b[d];
        d++;
    }
    for (i = y1 + 1; i <= y2; i++)
    {
        a[i][x2] = b[d];
        d++;
    }
    if (x1 < x2 && y1 < y2)
    {
        y1++;
        x2--;
        botton_left(x1,x2,y1,y2,a,b,d);
    }
}


void botton_left(int x1, int x2, int y1, int y2, int a[][10], int b[], int d)
{
    int i;
    for (i = x2; i >= x1; i--)
    {
        a[y2][i] = b[d];
        d++;
    }
    for (i = y2 - 1; i >= y1; i--)
    {
        a[i][x1] = b[d];
        d++;
    }
    if (x1 < x2 && y1 < y2)
    {
        x1++;
        y2--;
        top_right(x1,x2,y1,y2,a,b,d);
    }
}

void in_matrix(int a[][10],int n)
{
    int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}

int main()
{
    int a[10][10], b[100];
    int n, d = 0;
    scanf("%d", &n);
    finbonanci(b,n);
    int x1 = 0, x2 = n - 1;
    int y1 = 0, y2 = n - 1;
    top_right(x1,x2,y1,y2,a,b,d);
    in_matrix(a,n);
    return 0;
}


void finbonanci(int b[], int n)
{
    int i;
    b[0] = 0;
    b[1] = 1;
    for (i = 0; i < n * n; i++)
    {
        if (i > 1)
        {
            b[i] = b[i - 1] + b[i - 2];
        }
    }
}