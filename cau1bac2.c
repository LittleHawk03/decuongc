#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void giai_phuong_trinh(float a, float b, float c)
{
    if (a == 0)
    {
        if (b == 0 && c == 0)
        {
            printf("phuong trinh co vo so nghiem \n");
        }
        else if (b == 0 && c != 0)
        {
            printf("phuong trinh vo nhgiem\n");
        }
        else
        {
            printf("phuong trinh co nghiem la : %.2f", -c / b);
        }
    }
    else
    {
        int delta;
        delta = b * b - 4 * a * c;
        if (delta == 0)
        {
            printf("phuong trinh co nghiem kep x1 = x2 = %.2f", -b / (2 * a));
        }
        else if (delta > 0)
        {
            printf("phuong trinh co 2 nghiem phan biet \n");
            printf("X1 = \n", (-b + sqrt(delta)) / (2 * a));
            printf("X2 = \n", (-b - sqrt(delta)) / (2 * a));
        }
        else
        {
            printf("phuong trinh vo nghiem\n");
        }
        
    }
}
int main()
{
    float a, b, c;
    printf("nhap cac so a b c cua phuong trinh ax^2+bx+c : ");
    scanf("%f %f %f", &a, &b, &c);
    giai_phuong_trinh(a, b, c);
    return 0;
}