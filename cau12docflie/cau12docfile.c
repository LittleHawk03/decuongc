#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char sdt[30];
    int sotien;
    long tong;
} List;

FILE *fp;
const char *name = "C:\\Trenlop10\\cau12docflie\\SO_LIEU.C";

void In_file(int n)
{
    int i;
    List sp;
    fp = fopen(name, "wb");
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("so dien thoai : ");
        gets(sp.sdt);
        printf("don gia : ");
        scanf("%d", &sp.sotien);
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
    if (m >= 2)
    {
        while (i < m)
        {
            fflush(stdin);
            printf("so dien thoai : ");
            gets(sp.sdt);
            printf("don gia : ");
            scanf("%d", &sp.sotien);
            fwrite(&sp, sizeof(sp), 1, fp);
            i++;
        }
        *n = *n + m;
        printf("bo sung thanh cong\n");
    }
    else
    {
        printf("nhap lai so nguoi lon hon 2\n");
    }
    
    fclose(fp);
}

void hienthi(int n)
{
    List sp;
    int i;
    long tong = 0;
    fp = fopen(name, "rb");
    printf("-------------DANH SACH UNG HO QUY VACXIN--------------\n");
    printf("%-10s %-33s %-8s\n", "stt", "so dien thoai", "so tien");
    for (i = 1; i <= n; i++)
    {
        fread(&sp, sizeof(List), 1, fp);
        printf("%-10d %-33s %-8d\n", i, sp.sdt, sp.sotien);
        tong = tong + sp.sotien;
    }
    printf("\n");
    printf("                                        TONG TIEN : %ld\n", tong);
    fclose(fp);
}

int main()
{
    int n, t;
    printf("1.	Nhap so lieu\n");
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
                printf("nhap so luong nguoi : ");
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