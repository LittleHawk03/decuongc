#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TNode
{
    char ten[100];
    int tuoi;
    float diem;
    struct TNode *next;
} TNode;

typedef struct
{
    TNode *first;
    TNode *last;
} List;

TNode *NodeLT;

void tao_ds_rong(List *plist)
{
    plist->first = NULL;
    plist->last = NULL;
}

TNode *tao_node_moi(char ten[], int tuoi, float diem)
{
    TNode *node = (TNode *)malloc(sizeof(TNode));
    strcpy(node->ten, ten);
    node->tuoi = tuoi;
    node->diem = diem;
    node->next = NULL;
    return node;
}

void tao_ds(List *plist, int n)
{
    int i, tuoi;
    char s[100];
    float diem;
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("nhap ten :\n");
        gets(s);
        printf("nhap tuoi :\n");
        scanf("%d", &tuoi);
        printf("nhap diem :\n");
        scanf("%f", &diem);

        TNode *node = tao_node_moi(s, tuoi, diem);
        if (i == 0)
        {
            plist->first = node;
            plist->last = node;
        }
        else
        {
            plist->last->next = node;
            plist->last = node;
        }
    }
    printf("Tao danh sach thanh cong\n");
}

void show(List *plist)
{
    TNode *node = plist->first;
    int i = 1;
    printf("%-10s %-35s %-10s %-10s\n", "stt", "Ho Ten", "Tuoi", "DiemTB");
    while (node != NULL)
    {
        printf("%-10d %-35s %-10d %-10.2f\n", i, node->ten, node->tuoi, node->diem);
        node = node->next;
        i++;
    }
}

TNode *search(List *plist, char name[])
{
    TNode *node = plist->first;
    NodeLT = NULL;
    while (node != NULL && strcmp(node->ten, name) != 0)
    {
        NodeLT = node;
        node = node->next;
    }
    return node;
}

void them_sinh_vien(List *plist, char getname[], int tuoi, float diem)
{
    char name[100];
    int flag = 0;
    TNode *node = tao_node_moi(getname, tuoi, diem);
    fflush(stdin);
    printf("nhap ten sinh vien chen vao sau :\n");
    gets(name);
    TNode *nodelt = search(plist, name);
    if (nodelt != NULL)
    {
        node->next = nodelt->next;
        nodelt->next = node;
        printf("them thanh cong\n");
    }
    else
    {
        printf("ko ton tai sinh vien\n");
    }
}

void xoa_sinh_vien(List *plist, char getname[])
{
    TNode *node = search(plist, getname);
    if (node != NULL)
    {
        if (plist->first == node)
        {
            plist->first = node->next;
        }
        else if (plist->last == node)
        {
            NodeLT->next = NULL;
            plist->last = NodeLT;
        }
        else
        {
            NodeLT->next = node->next;
        }
        free(node);
    }
    else
    {
        printf("khong tim thay sinh vien do\n");
    }
}

void sua_sinh_vien(List *plist, char getname[])
{
    TNode *node = search(plist, getname);
    char name[100];
    int tuoi;
    float diem;
    fflush(stdin);
    printf("nhap ten :\n");
    gets(name);
    printf("nhap tuoi :\n");
    scanf("%d", &tuoi);
    printf("nhap diem :\n");
    scanf("%f", &diem);

    strcpy(node->ten, name);
    node->tuoi = tuoi;
    node->diem = diem;
    printf("sua sinh vien thanh cong\n");
}

int main()
{
    List *plist = (List *)malloc(sizeof(List));
    tao_ds_rong(plist);
    int n, t, tuoi;
    float diem;
    char getname[100];

    printf("1.	Tao danh sach sinh vien  \n");
    printf("2.	Hien thi danh sach sinh vien  \n");
    printf("3.	Chen them sinh vien  \n");
    printf("4.	Xoa mot sinh vien \n");
    printf("5.	Sua mot sinh vien \n");
    printf("6.	Ket thuc\n");
    while (1)
    {
        printf("lua chon so : ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("nhap so luong sinh vien : ");
            scanf("%d", &n);
            tao_ds(plist, n);
            break;
        case 2:
            show(plist);
            break;
        case 3:
            fflush(stdin);
            printf("nhap ten :\n");
            gets(getname);
            printf("nhap tuoi :\n");
            scanf("%d", &tuoi);
            printf("nhap diem :\n");
            scanf("%f", &diem);
            them_sinh_vien(plist, getname, tuoi, diem);
            break;
        case 4:
            fflush(stdin);
            printf("nhap ten sinh vien can xoa :\n");
            gets(getname);
            xoa_sinh_vien(plist, getname);
            break;
        case 5:
            fflush(stdin);
            printf("nhap ten sinh vien can sua :\n");
            gets(getname);
            sua_sinh_vien(plist,getname);
            break;
        }
        if (t == 6)
        {
            printf("ket thu truong trinh");
            break;
        }
    }

    return 0;
}