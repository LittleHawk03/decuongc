#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct SinhVien
{
    char Hoten[25];
    char Lop[25];
    int Tuoi;
    struct SinhVien *next;

} SinhVien;

typedef struct List
{
    SinhVien *first;
    SinhVien *last;
} List;

SinhVien *nodelientruoc;

void Taodanhsach(List *plist)
{
    plist->first = NULL;
    plist->last = NULL;
}

SinhVien *tao_node_moi(char Hoten[], char Lop[], int Tuoi)
{
    SinhVien *node = (SinhVien *)malloc(sizeof(SinhVien));
    strcpy(node->Hoten, Hoten);
    strcpy(node->Lop, Lop);
    node->Tuoi = Tuoi;
    node->next = NULL;
    return node;
}
void Themvaodau(List *plist, char Hoten[], char Lop[], int Tuoi)
{
    SinhVien *node = tao_node_moi(Hoten, Lop, Tuoi);
    plist->first = node;
    plist->last = node;
}
void Themvaocuoi(List *plist, char Hoten[], char Lop[], int Tuoi)
{
    SinhVien *node = tao_node_moi(Hoten, Lop, Tuoi);
    plist->last->next = node;
    plist->last = node;
}

void ThemvaoDSLK(List *plist, char Hoten[], char Lop[], int Tuoi)
{
    if (plist->first == NULL)
    {
        Themvaodau(plist, Hoten, Lop, Tuoi);
    }
    else
    {
        Themvaocuoi(plist, Hoten, Lop, Tuoi);
    }
}

void NhapvaThemvaoDSLK(List *plist)
{

    printf("Nhap Ho va Ten:");
    char Hoten[25];
    fflush(stdin);
    gets(Hoten);
    printf("Nhap Lop:");
    char Lop[25];
    fflush(stdin);
    gets(Lop);
    printf("Nhap Tuoi:");
    int Tuoi;
    scanf("%d", &Tuoi);

    ThemvaoDSLK(plist, Hoten, Lop, Tuoi);
}
SinhVien *Timkiemtheoten(List *plist, char Hoten[])
{

    SinhVien *node = plist->first;
    if (node != NULL)
    {
        while (node != NULL)
        {
            if (strcmp(node->Hoten, Hoten) == 0)
            {
                return node;
            }
            nodelientruoc = node;
            node = node->next;
        }
    }
    return NULL;
}

void NhapvaXoaSinhVientheoten(List *plist)
{
    char Hoten[25];
    fflush(stdin);
    gets(Hoten);

    SinhVien *node = Timkiemtheoten(plist, Hoten);
    if (node != NULL)
    {
        if (node == plist->first)
        {
            plist->first = node->next;
        }
        else
        {
            nodelientruoc->next = node->next;
            if (node == plist->last)
            {
                plist->last = nodelientruoc;
            }
        }
        free(node);
    }
}

void Indanhsach(List *plist)
{
    SinhVien *node = plist->first;
    if (node != NULL)
    {
        while (node != NULL)
        {

            printf("\t%s\t%12s\t%20d\n", node->Hoten, node->Lop, node->Tuoi);
            node = node->next;
        }
    }
}

int main()
{
    List *plist = (List *)malloc(sizeof(List));
    Taodanhsach(plist);
    char Hoten[25];
    char Lop[25];
    int id, Tuoi;
    while (1)
    {
        scanf("%d", &id);
        switch (id)
        {
        case 1:
            NhapvaThemvaoDSLK(plist);
            break;
        case 2:
            printf("\tHoten\t\t|\tLop\t|\t\tTuoi\n");
            Indanhsach(plist);
            break;
        case 3:
            printf("Nhap Ten can xoa:\n");
            NhapvaXoaSinhVientheoten(plist);
            break;
        }
    }
}
