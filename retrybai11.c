#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TNode
{
    char ten[30];
    int tuoi;
    float diem;
    struct TNode *next;
} TNode;

typedef struct
{
    TNode *first;
    TNode *last;
} List;

void init(List *plist)
{
    plist->first = NULL;
    plist->last = NULL;
}

TNode *tao_node(char ten[], int tuoi, float diem)
{
    TNode *node = (TNode *)malloc(sizeof(malloc));
    strcpy(node->ten, ten);
    node->tuoi = tuoi;
    node->diem = diem;
    node->next = NULL;
    return node;
}

void nhap_list(List *plist, int n)
{
    char ten[35];
    int i, tuoi;
    float diem;

    for (i = 0; i < n; i++)
    {
        printf("nhap ten sinh vien :\n");
        fflush(stdin);
        gets(ten);
        printf("nhap tuoi sinh vien :\n");
        scanf("%d", &tuoi);
        printf("nhap diem tb cua sinh vien:\n");
        scanf("%f", &diem);

        TNode *node = tao_node(ten, tuoi, diem);
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
    printf("da tao sach thanh cong\n");
}

TNode *nodeLT;

TNode *search(List *plist, char getname[])
{
    TNode *node = plist->first;
    nodeLT = NULL;
    while (node != NULL && strcmp(node->ten, getname) != 0)
    {
        nodeLT = node;
        node = node->next;
    }
    return node;
}

void them_vao_sau(List *plist, char getname[])
{
    char ten[35];
    int i, tuoi;
    float diem;

    printf("nhap ten sinh vien can them:\n");
    fflush(stdin);
    gets(ten);
    printf("nhap tuoi sinh vien :\n");
    scanf("%d", &tuoi);
    printf("nhap diem tb cua sinh vien:\n");
    scanf("%f", &diem);

    TNode *node = tao_node(ten, tuoi, diem);
    TNode *nodelt = search(plist, getname);

    if (nodelt != NULL)
    {
        node->next = nodelt->next;
        nodelt->next = node;
        printf("them sinh vien thanh cong\n");
    }
    else
    {
        printf("khong tim thay sinh vien\n");
    }
}

void xoa_sinh_vien(List *plist, char getname[])
{
    TNode *node = search(plist, getname);
    if (node != NULL)
    {
        if (node == plist->first)
        {
            plist->first = node->next;
        }
        else if (node == plist->last)
        {
            plist->last = nodeLT;
        }
        else
        {
            nodeLT->next = node->next;
        }
        free(node);
        printf("xoa sinh vien thanh cong\n");
    }
    else
    {
        printf("khong tim thay sinh vien do\n");
    }
}

void sua_sinh_vien(List *plist, char getname)
{
    char ten[35];
    int i, tuoi;
    float diem;

    TNode *node = search(plist, getname);

    printf("nhap ten sinh vien thay the:\n");
    fflush(stdin);
    gets(ten);
    printf("nhap tuoi sinh vien :\n");
    scanf("%d", &tuoi);
    printf("nhap diem tb cua sinh vien:\n");
    scanf("%f", &diem);

    strcpy(node->ten, ten);
    node->tuoi = tuoi;
    node->diem = diem;
    printf("sua sinh vien thanh cong\n");
}

void show(List *plist)
{
    TNode *node = plist->first;
    int i = 1;
    printf("%4s %35s %10s %10s", "stt", "ho va ten", "tuoi", "diem");
    while (node != NULL)
    {
        printf("%4s %35s %10s %10s", i, node->ten, node->tuoi, node->diem);
        i++;
        node = node->next;
    }
    printf("\n");
}

int main()
{
    List *plist = (List *)malloc(sizeof(List));
    init(plist);
    int t, n;
    char getname[35];
    printf("1.	Tao danh sach sinh vien \n");
    printf("2.	Hien thi danh sach sinh vien \n");
    printf("3.	Chen them sinh vien \n");
    printf("4.	Xóa một sinh viên\n");
    printf("5.	Sửa một sinh viên\n");
    printf("6.	Ket thuc\n");
    while (1)
    {
        printf("lua chon : ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("nhap so luong sinh vien : ");
            scanf("%d", &n);
            nhap_list(plist, n);
            break;
        case 2:
            show(plist);
            break;
        case 3:
            printf("nhap ten sinh vien can them vao sau:\n");
            fflush(stdin);
            gets(getname);
            them_vao_sau(plist, getname);
            break;
        case 4:
            printf("nhap ten sinh vien can xoa:\n");
            fflush(stdin);
            gets(getname);
            xoa_sinh_vien(plist,getname);
            break;
        case 5:
             printf("nhap ten sinh vien can sua:\n");
            fflush(stdin);
            gets(getname);
            sua_sinh_vien(plist,getname);
            break;
        }
        if (t == 6)
        {
            printf("finish\n");
            break;
        }
    }
    return 0;
}