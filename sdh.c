#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 105
typedef struct SinhVien
{
    char Ho_ten[MAX_LEN];
    int Tuoi;
    float Diem_TB;
    struct SinhVien *next;

} SinhVien;

typedef struct List
{
    SinhVien *first;
    SinhVien *last;

} List;

void init(List *plist)
{
    plist->first = NULL;
    plist->last = NULL;
}

SinhVien *Tao_node_moi(char Ho_ten[], int Tuoi, float Diem_TB)
{
    SinhVien *node = (SinhVien *)malloc(sizeof(SinhVien));
    strcpy(node->Ho_ten, Ho_ten);
    node->Diem_TB = Diem_TB;
    node->Tuoi = Tuoi;
    node->next = NULL;
    return node;
}
void them_vao_dau(List *plist, char Ho_ten[], int Tuoi, float Diem_TB)
{
    SinhVien *node = Tao_node_moi(Ho_ten, Tuoi, Diem_TB);
    plist->first = node;
    plist->last = node;
}
void them_vao_cuoi(List *plist, char Ho_ten[], int Tuoi, float Diem_TB)
{
    SinhVien *node = Tao_node_moi(Ho_ten, Tuoi, Diem_TB);
    plist->last->next = node;
    plist->last = node;
}

void ThemvaoDSLK(List *plist, char Ho_ten[], int Tuoi, float Diem_TB)
{
    if (plist->first == NULL)
    {
        them_vao_dau(plist, Ho_ten, Tuoi, Diem_TB);
    }
    else
    {
        them_vao_cuoi(plist, Ho_ten, Tuoi, Diem_TB);
    }
}
void NhapvaThemvaoDSLK(List *plist, int t)
{
    int i;
    for (i = 0; i < t; i++)
    {
        char Ho_ten[MAX_LEN];
        int Tuoi;
        float Diem_TB;
        fflush(stdin);
        printf("Nhap Ten:\n");
        gets(Ho_ten);
        printf("Nhap Tuoi:\n");
        scanf("%d", &Tuoi);
        printf("Nhap DiemTB:\n");
        scanf("%f", &Diem_TB);
        ThemvaoDSLK(plist, Ho_ten, Tuoi, Diem_TB);
    }
}
void InDanhSach(List *plist)
{
    SinhVien *node = plist->first;
    printf("STT\tHo va ten\tDiemTB\n");
    while (node != NULL)
    {
        printf("%s%10d%10f\n", node->Ho_ten, node->Tuoi, node->Diem_TB);
        node = node->next;
    }
    
}

int main()
{
    List *plist = (List *)malloc(sizeof(List));
    init(plist);
    int id, n, t;
    while (1)
    {
        scanf("%d", &id);
        switch (id)
        {
        case 1:
            printf("nhap so luong sinh vien : ");
            scanf("%d", &t);
            NhapvaThemvaoDSLK(plist, t);
            break;
        case 2:
            InDanhSach(plist);
            break;
        }
        if (id == 6)
        {
            break;
        }
        
    }
    return 0;
}
