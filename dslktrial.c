#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TNode
{
    char ten[30];
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

TNode *creatNode(char hoten[], float diem)
{
    TNode *node = (TNode *)malloc(sizeof(TNode));
    strcpy(node->ten, hoten);
    node->diem = diem;
    node->next = NULL;
    return node;
}

void creat_first_node(List *plist, TNode *node)
{
    plist->first = node;
    plist->last = node;
}

void add_to_last(List *plist, TNode *node)
{
    plist->last->next = node;
    plist->last = node;
}

void nhap_VS(List *plist, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        char ten[30];
        float diem;
        fflush(stdin);
        printf("nhap ten sinh vien : \n");
        gets(ten);
        printf("nhap diem sinh vien : \n");
        scanf("%f", &diem);
        if (i == 0)
        {
            creat_first_node(plist, creatNode(ten, diem));
        }
        else
        {
            add_to_last(plist, creatNode(ten, diem));
        }
        printf("\n");
    }
}

void show_list(List *plist)
{
    TNode *node = plist->first;
    while (node != NULL)
    {
        printf("%-30s %20.2f\n", node->ten, node->diem);
        node = node->next;
    }
    printf("\n");
}

void tren_after(List *plist, char name[])
{
    char ten[30];
    float diem;
    int flag = 0;
    fflush(stdin);
    printf("nhap ten sinh vien chen: \n");
    gets(ten);
    printf("nhap diem sinh vien chen: \n");
    scanf("%f", &diem);
    TNode *nodeis = creatNode(ten, diem);
    TNode *node = plist->first;
    while (node != NULL)
    {
        if (strcmp(node->ten, name) == 0)
        {
            nodeis->next = node->next;
            node->next = nodeis;
            flag = 1;
            break;
        }
        node = node->next;
    }
    if (flag == 0)
    {
        printf("khong ton tai sinh vien nay\n");
    }
}

TNode *nodeLT;

TNode *Search(List *pList, char getName[])
{

    TNode *node = pList->first;
    nodeLT = NULL;
    while (node != NULL && strcmp(node->ten, getName) != 0)
    {
        nodeLT = node;
        node = node->next;
    }
    return node;
}

void xoa_node(List *plist, char name[])
{
    TNode *node = Search(plist, name);
    if (node != NULL)
    {
        if (plist->first == node)
        {
            plist->first = node->next;
        }
        else if (plist->last == node)
        {
            nodeLT->next = NULL;
            plist->last = nodeLT;
        }
        else
        {
            nodeLT->next = node->next;
        }
        free(node);
        printf("da xoa thanh cong\n");
    }
    else
    {
        printf("khong co ke ten %s \n",name);
    }
    
}

int main()
{
    int n;
    char name[30];
    List *plist = (List *)malloc(sizeof(List));
    init(plist);
    printf("nhap so luong sinh vien : ");
    scanf("%d", &n);
    nhap_VS(plist, n);
    show_list(plist);
    printf("nhap ten sinh vien can chen vao sau : \n");
    fflush(stdin);
    gets(name);
    tren_after(plist, name);
    show_list(plist);
    printf("nhap ten sinh vien can xoa : \n");
    fflush(stdin);
    gets(name);
    xoa_node(plist,name);
    show_list(plist);
    return 0;
}