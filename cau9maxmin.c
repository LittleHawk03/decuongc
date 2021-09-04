#include<stdio.h>
#include<stdlib.h>

void nhap_matrix(int a[],int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
}



int main()
{
    int a[100],n;
    int max,min;
    int maxps,minps;
    printf("nhap so luong phan tu cua mang : ");
    scanf("%d",&n);
    nhap_matrix(a,n);
    int i;

    max = a[0];
    min = a[0];

    maxps = 0;
    minps = 0;

    for ( i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            maxps = i;
        }
        if (a[i] < min)
        {
            min = a[i];
            minps = i;
        }
        
    }
    printf("MAX = %d\n",max);
    printf("MAX position = %d\n",maxps+1);
    printf("MIN = %d\n",min);
    printf("MIN position = %d",minps+1);

    return 0;
}