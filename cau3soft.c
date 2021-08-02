#include <stdio.h>
#include <stdlib.h>
void nhap_mang(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void soft(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void in_mang(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
int main()
{

    int a[100], n;
    printf("so luong phan tu cua day : ");
    scanf("%d", &n);
    nhap_mang(a, n);
    in_mang(a, n);
    soft(a, n);
    in_mang(a, n);
    return 0;
}