#include<stdio.h>
#include<stdlib.h>
void nhap_mang(int *a,int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
}
void soft(int *a,int n)
{
    int i,j;
    int temp;
    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n-1; j++)
        {
            if(a[i] < a[j])
            {
               temp = a[j];
               a[j] = a[i];
               a[i] = temp;    
            }
        }
        
    }
    for ( i = 0; i < n; i++)
    {
        if (a[0] > a[i])
        {
            printf("%d %d",a[0],a[i]);
            break;
        }
        
    }
    
    
    
}
int main()
{
    int *a,n;
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    nhap_mang(a,n);
    soft(a,n);
    return 0;
}