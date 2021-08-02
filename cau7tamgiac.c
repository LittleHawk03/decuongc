#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c;
    printf("nhap ba canh tam giac a,b,c : ");
    scanf("%d %d %d", &a, &b, &c);
    if (b + c > a || a + c > b || a + b > c)
    {
        if (a == b == c)
        {
            printf("tam gia deu");
        }
        else if ((a == b && a != c) || (b == c && c != a) || (a == c && a != b))
        {
            printf("tam giac can");
        }
        else if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b)
        {
            if (a == b || b == c || c == a)
            {
                printf("tam giac vuong can");
            }
            else
            {
                printf("tam giac vuong");
            }
        }
    }
    else
    {
        printf(".....");
    }

    return 0;
}