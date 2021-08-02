#include <stdio.h>
#include <stdlib.h>
int main()
{
    float gdp, rgdp;
    printf("GDP 2014  = ");
    scanf("%f", &gdp);
    printf("ti le tang truong kinh te nam 2014  = ");
    scanf("%f", &rgdp);
    int nam = 2014;
    float gdp2 = gdp;


    printf("%-8s %-8s\n", "Nam", "GDP");
    while (gdp2 <= 2 * gdp)
    {
        printf("%-8d %-8.2f\n",nam,gdp2);
        nam++;
        gdp2 = gdp2 + rgdp * gdp2;
    }

    return 0;
}