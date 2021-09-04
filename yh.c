#include <stdio.h>
#include <stdlib.h>

typedef struct SO
{
    int n;
    struct SO *next;
} SO;

typedef struct DAY
{
    SO *SoDAU_DAY;
    SO *SoCUOI_DAY;
} DAY;

void Khoitao(DAY *pday)
{
    pday->SoCUOI_DAY = NULL;
    pday->SoDAU_DAY = NULL;
}
void themvaocuoi(DAY *pday, int a)
{
    SO *node = (SO *)malloc(sizeof(SO));
    node->n = a;
    node->next = NULL;
    if (pday->SoCUOI_DAY == NULL)
    {
        pday->SoCUOI_DAY = pday->SoDAU_DAY = node;
    }
    else
    {
        pday->SoCUOI_DAY->next = node;
        pday->SoCUOI_DAY = node;
    }
}
void NhapDay(DAY *pday)
{
    while (1)
    {
        int a;
        scanf("%d", &a);
        if (a == 0)
        {
            themvaocuoi(pday, a);
            break;
        }
        themvaocuoi(pday, a);
    }
}

void XuatDay(DAY *pday)
{
    SO *node = pday->SoDAU_DAY;
    while (node != NULL)
    {
        printf("%d ", node->n);
        node = node->next;
    }
}
int main()
{
    DAY *pday = (DAY *)malloc(sizeof(DAY));
    Khoitao(pday);
    NhapDay(pday);
    XuatDay(pday);
    return 0;
}
