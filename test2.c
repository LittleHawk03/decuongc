#include<stdio.h>
#include<stdlib.h>
void dao(int a)
{
    int tmp =0 ,res;
    while (a > 0)
    {
        res = a%10;
        tmp = tmp * 10 + res;
        a =a /10;
    }
    printf("%d",tmp);
}
int main()
{
    int a;
    scanf("%d",&a);
    dao(a);
    return 0;
}