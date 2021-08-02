#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ten[30];
    int dongia;
    int soluog;
    long tong;
} List;

FILE *fp;
const char *name = "C:\\Trenlop10\\cau12docflie\\SO_LIEU.txt";

void In_file(int n)
{
    int i;
    List sp;
    fp = fopen(name, "wb");
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("ten mat hang : ");
        gets(sp.ten);
        printf("don gia : ");
        scanf("%d", &sp.dongia);
        printf("so luong : ");
        scanf("%d", &sp.soluog);
        sp.tong = sp.soluog * sp.dongia;
        fwrite(&sp, sizeof(List), 1, fp);
    }
    printf("them thanh cong\n");
    fclose(fp);
}

void ghi_bo_sung(int *n)
{
    int m, i = 0;
    List sp;
    fp = fopen(name, "ab");

    printf("\tthem it nhat 2 phan tu vao file.\n");
    printf("\tnhap so san pham them vao : ");
    scanf("%d", &m);

    while (i < m)
    {
        fflush(stdin);
        printf("ten mat hang : ");
        gets(sp.ten);
        printf("don gia : ");
        scanf("%d", &sp.dongia);
        printf("so luong : ");
        scanf("%d", &sp.soluog);
        sp.tong = sp.soluog * sp.dongia;
        fwrite(&sp, sizeof(sp), 1, fp);
        i++;
    }
    *n = *n + m;
    printf("bo sung thanh cong\n");
    fclose(fp);
}

void hienthi(int n)
{
    List sp;
    int i;
    long tong = 0;
    fp = fopen(name, "rb");
    printf("------------------SO LIEU BAN HANG------------------\n");
    printf("%2s %33s %8s %9s\n", "stt", "Ten Hang", "Don Gia", "So Luong");
    for (i = 1; i <= n; i++)
    {
        fread(&sp, sizeof(List), 1, fp);
        printf("%2d %33s %8d %9d\n", i, sp.ten, sp.dongia, sp.soluog);
        tong = tong + sp.tong;
    }
    printf("\n");
    printf("                                        TONG TIEN : %ld", tong);
    fclose(fp);
}

int main()
{
    int n, t;
    printf("1.	Nhap so lieu ban hang len tep\n");
    printf("2.	Ghi bo sung so lieu ban hang vao cuoi tep SO_LIEU.C\n");
    printf("3.	Hien thi noi dung tep SO_LIEU.C\n");
    printf("4.	Ket thuc\n");
    while (1)
    {
        printf("lua chon la : ");
        scanf("%d", &t);
        if (t < 0 || t > 4)
        {
            printf("ko co lua chon do . vui long chon lai\n");
        }
        else
        {
            switch (t)
            {
            case 1:
                printf("nhap so luong mat hang : ");
                scanf("%d", &n);
                In_file(n);
                break;
            case 2:
                ghi_bo_sung(&n);
                break;
            case 3:
                hienthi(n);
                break;
            }
            if (t == 4)
            {
                printf("finish");
                break;
            }
        }
    }

    return 0;
}