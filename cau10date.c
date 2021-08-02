#include <stdio.h>
#include <stdlib.h>
int main()
{
    int month, year;
    scanf("%d %d", &month, &year);
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("thang %d nam %d co %d ngay", month, year, 31);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("thang %d nam %d co %d ngay", month, year, 30);
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            printf("thang %d nam %d co %d ngay", month, year, 29);
        }
        else
        {
            printf("thang %d nam %d co %d ngay", month, year, 28);
        }
        
        break;
    }
    return 0;
}