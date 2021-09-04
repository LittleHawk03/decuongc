#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode
{
    char ten[105];
    int date;
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

TNode *creat_new_node(char s[],int a)
{
    TNode *node = (TNode *)malloc(sizeof(TNode));
    strcpy(node->ten, s);
    node->date = a;
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

void show_list(List *plist)
{
    TNode *node = plist->first;
    while (node != NULL)
    {
        printf("%s (%d)\n",node->ten,node->date);
        node = node->next;
    }
}


void nhap(List *plist, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        char s[105];
        int a;
        scanf("\n");
        gets(s);
        scanf("%d", &a);
        if (i == 0)
        {
            creat_first_node(plist, creat_new_node(s,a));
        }
        else
        {
            add_to_last(plist,creat_new_node(s,a));
        }
        
    }
}

int main()
{
    List *plist = (List*)malloc(sizeof(List));
    init(plist);
    int n;
    scanf("%d\n",&n);
    nhap(plist,n);
    show_list(plist);
    return 0;
}