#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 105
typedef struct Tnode
{
    char ten[MAX_LEN];
    int soLuong;
    int gia;
    struct Tnode *next;
} Tnode;

typedef struct
{
    Tnode *first;
    Tnode *last;
} TList;

Tnode *nodeLT;

void init(TList *plist)
{
    plist->first = NULL;
    plist->last = NULL;
}

Tnode *creatnode(char ten[], int soluong, int Gia)
{
    Tnode *node = (Tnode *)malloc(sizeof(Tnode));
    strcpy(node->ten, ten);
    node->soLuong = soluong;
    node->gia = Gia;
    node->next = NULL;
    return node;
}

Tnode *nhap()
{
    char ten[MAX_LEN];
    int soLuong;
    int gia;
    scanf("%s%d%d", &ten, &soLuong, &gia);
    return creatnode(ten, soLuong, gia);
}

void creatfirstnode(TList *pList, Tnode *node)
{
    pList->first = node;
    pList->last = node;
}

void insert_last(TList *pList, Tnode *node)
{
    pList->last->next = node;
    pList->last = node;
}



Tnode *Search(TList *pList, char getName[])
{

    Tnode *node = pList->first;
    nodeLT = NULL;
    while (node != NULL && strcmp(node->ten, getName) != 0)
    {
        nodeLT = node;
        node = node->next;
    }
    return node;
}

void delete_note(TList *pList, char getName[])
{
    Tnode *node = Search(pList, getName);
    if (node != NULL)
    {
        if (pList->first == node)
        {
            pList->first = node->next;
        }
        else if (pList->last == node)
        {
            nodeLT->next = NULL;
            pList->last = nodeLT;
        }
        else
        {
            nodeLT->next = node->next;
        }
        free(node);
    }
}

void Search_printf(TList *pList, char getName[])
{
    Tnode *node = Search(pList, getName);
    if (node != NULL)
    {
        printf("%s%10d%10d\n", node->ten, node->soLuong, node->gia);
    }
    else
        printf("Khong ton tai san pham: %s\n", getName);
}

void Search_change(TList *pList, char getName[], int y, int getValue)
{
    Tnode *node = Search(pList, getName);
    if (node != NULL)
    {
        if (y == 1)
        {
            node->soLuong = getValue;
        }
        else if (y == 2)
        {
            node->gia = getValue;
        }
    }
    else
    {
        printf("Khong the sua thong tin san pham: %s\n", getName);
    }
}

void Show(TList *pList)
{
    Tnode *node = pList->first;
    while (node != NULL)
    {
        printf("%s%10d%10d\n", node->ten, node->soLuong, node->gia);
        node = node->next;
    }
}

int main()
{

    Tnode *node;
    TList *pList = (TList *)malloc(sizeof(TList));
    init(pList);
    int t, a;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &a);
        switch (a)
        {
        case 1:
        {
            node = nhap();
            if (pList->first == NULL)
            {
                creatfirstnode(pList, node);
            }
            else
            {
                insert_last(pList, node);
            }

            break;
        }
        case 2:
        {
            char getName[MAX_LEN];
            scanf("%s", &getName);
            delete_note(pList, getName);
            break;
        }
        case 3:
        {
            char getName[MAX_LEN];
            scanf("%s", &getName);
            Search_printf(pList, getName);
            break;
        }
        case 4:
        {
            char getName[MAX_LEN];
            int y, getValue;
            scanf("%s%d%d", &getName, &y, &getValue);
            Search_change(pList, getName, y, getValue);
            break;
        }
        case 5:
        {
            Show(pList);

            break;
        }
        }
    }
    return 0;
}