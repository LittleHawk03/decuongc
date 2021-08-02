#include <stdio.h>
#include <stdlib.h>

#define max_size 100

typedef struct
{
    int value;

} STACK;

STACK stack[max_size];
int top;

int is_full()
{
    if (top == max_size)
    {
        return 1;
    }
    return 0;
}

int is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void push(int du)
{
    if (!is_full())
    {
        top++;
        if (0 <= du && du <= 9)
        {
            stack[top].value = du;
        }
        else if (10 <= du && du <= 15)
        {
            // ma ascii A = 65 tuong ung 10 + 55
            stack[top].value = du + 55;
        }
    }
    else
    {
        printf("stack da day khong the them");
    }
}

char pop()
{
    if (!is_empty())
    {
        int res = stack[top].value;
        top--;
        return res;
    }
    else
    {
        printf("stack trong khong");
        return -1;
    }
}

void chuyen_co_so(int n, int coso)
{
    int du;
    while (n != 0)
    {
        du = n % coso;
        n = n / coso;
        push(du);
    }
    printf("chuyen co so thanh cong\n");
}

void in_stack(int n, int coso)
{
    printf("%d tren co so %d : ", n, coso);
    while (!is_empty())
    {
        int data = pop();
        if (data >= 0 && data <= 9)
        {
            printf("%d", data);
        }
        else if (data <= 'F' && data >= 'A')
        {
            printf("%c", data);
        }
    }
    printf("\n\n");
}

int main()
{
    top = -1;
    int t;
    int n, coso;
    printf("1.	Chuyen mot so nguyen dương sang he 2\n");
    printf("2.	Chuyen mot so nguyen dương sang he 8\n");
    printf("3.	Chuyen mot so nguyen dương sang he 16\n");
    printf("4.	Ket thuc\n");
    while (1)
    {
        printf("lua chon : ");
        scanf("%d", &t);
        if (t >= 0 && t < 5)
        {
            switch (t)
            {
            case 1:
                printf("nhap so can chuyen doi : ");
                scanf("%d", &n);
                chuyen_co_so(n, 2);
                in_stack(n, 2);
                break;
            case 2:
                printf("nhap so can chuyen doi : ");
                scanf("%d", &n);
                chuyen_co_so(n, 8);
                in_stack(n, 8);
                break;
            case 3:
                printf("nhap so can chuyen doi : ");
                scanf("%d", &n);
                chuyen_co_so(n, 16);
                in_stack(n, 16);
                break;
            }
            if (t == 4)
            {
                printf("finish");
                break;
            }
        }
        else
        {
            printf("lua chon lai\n");
        }
        
    }

    return 0;
}