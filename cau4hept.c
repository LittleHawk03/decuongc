#include <stdio.h>
#include <stdlib.h>
int giai_phuong_trinh(int a, int b, int c, int d, int e, int f)
{
    int D = a * e - d * b, Dx = c * e - f * b, Dy = a * f - d * c;
    if (D == 0 && Dx == 0 && Dy == 0)
    {
        printf("phuong trinh co vo so nghiem :");
    }
    else if (D == 0 && (Dx != 0 || Dy != 0))
    {
        printf("phuong trinh co vo so nghiem :");
    }
    else
    {
        printf("X = %.2f\n",(float)(Dx/D));
        printf("Y = %.2f\n",(float)(Dy/D));
    }
    
}
int main()
{
    int a, b, c, d, e, f;
    //ax+by = c
    //dx+ey = f
    printf("nhap a b c cua ax + by = c : ");
    scanf("%d %d %d", &a, &b, &c);
    printf("nhap d e f cua dx + ey = f : ");
    scanf("%d %d %d", &d, &e, &f);
    giai_phuong_trinh(a,b,c,d,e,f);
    return 0;
}