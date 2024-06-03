/**
 * @file giao_dien_1.cpp
 * @author guwoh (hiep.vh234005@sis.hust.edu.vn)
 * @brief  He thong quan ly trung tam tiem trung
 * @version 0.1
 * @date 2024-06-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<stdio.h> // use for printf
#include<string.h> // use for string
#include<stdlib.h> // use for malloc in C

// khai bao struct 
typedef struct  // for nhan vien
{
    char nameofnv[100];
    int dayofnv;
    int monthofnv;
    int yearofnv;
    int codeofnv;
}nv;
typedef struct // for vaccin
{
    char nameofvc[100];
    int dayofvc;
    int monthofvc;
    int yearofvc;
    int codeofvc;
}vc;
typedef struct  // for benh nhan
{
    char nameofbn[100];
    int dayofbn;
    int monthofbn;
    int yearofbn;
    int codeofbn;
}bn;


// khai bao cac ham su dung 
void display_first(int*,int*,int*);  // hien thi giao dien ban dau, nhap so nhan vien, benh nhan, vaccin
void display_enter(int,int,int,nv*,vc*,bn*);  // hien thi nhap thong tin
void display_mid(int*,nv*,bn*,vc*);// hien thi giao dien giai doan 2, lua chon giua nhan vien va benh nhan
void if_nv(nv*,bn*,vc*);
void if_bn(bn*,vc*);


int main()
{
    int a;  
    nv* infor_nv; // thong tin nhan vien
    vc* infor_vc; // thong tin vaccin
    bn* infor_bn; // thong tin benh nhan
    int numofnv;  // so luong nhan vien
    int numofbn;  // so luong benh nhan
    int numofvc;  // so luong vaccin

    display_first(&numofnv, &numofbn, &numofvc); // chuyen dia chi so luong
    printf("\n Hien thi: %d-%d-%d\n",numofnv,numofbn,numofvc);
    // cap phat dong cho doi tuong
    infor_nv = (nv*)malloc(numofnv * sizeof(nv));
    infor_vc = (vc*)malloc(numofvc * sizeof(vc));
    infor_bn = (bn*)malloc(numofbn * sizeof(bn));

    // nhap thong tin cho bo nho cap phat dong
    display_enter(numofnv, numofvc, numofbn, infor_nv, infor_vc, infor_bn);
    // hien thi tuy chon tiep theo
    printf(" *********************************\n");
    printf(" ___HE THONG THONG TIN TIEM CHUNG___\n\n");
    display_mid(&a, infor_nv, infor_bn, infor_vc);
    // check for a value
    printf( " Hien thi a:%d ",a);
    switch(a)
    {
        case 1: // truong hop danh cho nhan vien
            if_nv(infor_nv,infor_bn,infor_vc);
            break;
        case 2: // truong hop cho benh nhan
            if_bn(infor_bn,infor_vc);
            break;
        defautl: break;
    }






    // Free allocated memory
    free(infor_bn);
    free(infor_nv);
    free(infor_vc);
    
    return 0;

}

void display_first(int *numofnv, int *numofbn, int *numofvc)
{
    int a,b,c;
    printf(" Nhap so luong (nhan vien)-(benh nhan)-(vaccin): ");
    scanf("%d-%d-%d",&a,&b,&c);
    *numofnv=a; *numofbn=b; *numofvc=c;
}

void display_enter(int n_v,int v_c,int b_n ,nv* in_nv,vc* in_vc,bn* in_bn)
{
    // printf("%d_%d_%d",n_v,v_c,b_n);
    for(int i=0; i<n_v; i++)  // for loop nhap thong tin nhan vien
    {
        printf(" Nhap ten cua nhan vien:");
        getchar();  // Doc ky tu newline con lai tu lan nhap truoc
        fgets(in_nv[i].nameofnv,99,stdin);
        printf("**\n");
        printf(" Nhap Nam-Thang-Ngay:");
        scanf("%4d-%2d-%d",&in_nv[i].yearofnv,&in_nv[i].monthofnv,&in_nv[i].dayofnv);
        printf("**\n");
        printf(" Ma code cua nhan vien nay la: ");
        scanf("%d",&in_nv[i].codeofnv);
    }

    for(int i=0; i<v_c; i++)  // for loop nhap thong tin vaccin
    {
        printf(" Nhap ten cua vaccin:");
        getchar();  // Doc ky tu newline con lai tu lan nhap truoc
        fgets(in_vc[i].nameofvc,99,stdin);
        printf("**\n");
        printf(" Nhap Nam-Thang-Ngay:");
        scanf("%4d-%2d-%d",&in_vc[i].yearofvc,&in_vc[i].monthofvc,&in_vc[i].dayofvc);
        printf("**\n");
        printf(" Ma code cua vaccin nay la: ");
        scanf("%d",&in_vc[i].codeofvc);
    }

    for(int i=0; i<b_n; i++)  // for loop nhap thong tin benh nhan
    {
        printf(" Nhap ten cua benh nhan:");
        getchar();  // Doc ky tu newline con lai tu lan nhap truoc
        fgets(in_bn[i].nameofbn,99,stdin);
        printf("**\n");
        printf(" Nhap Nam-Thang-Ngay:");
        scanf("%4d-%2d-%d",&in_bn[i].yearofbn,&in_bn[i].monthofbn,&in_bn[i].dayofbn);
        printf("**\n");
        printf(" Ma code cua benh nhan nay la: ");
        scanf("%d",&in_bn[i].codeofbn);
    }
}

void display_mid(int *a,nv*innv, bn*inbn, vc*invc)
{
    int gan;
    do
    {
        printf(" Ban la: nhan vien(1) benh nhan(2):");
        scanf("%d",&gan);
        switch(gan) 
        {
            case 1 : 
                printf(" Duoi day la cac tien ich cho nhan vien!\n");
                break;
            case 2 :
                printf(" Duoi day la cac tien ich cho benh nhan!\n");
                break;
            default: 
                printf(" Thong tin ban nhap khong hop le, vui long nhap lai!\n");
                gan=3;
                break;
        }
    /* code */
    } while (gan==3);
    *a=gan;
    // printf("\n gan %d:", gan);
}

void if_nv(nv*infor_nv,bn*infor_bn,vc*infor_vc) // co the thay doi, hien thi
{
    int option;
    do
    {
        printf(" Duoi day la cac options cua ban:\n Option 1 (1): Hien thi thong tin!\n Option 2 (2): Chinh sua thong tin");
        printf("\n******************\n Chon options: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: // Hien thi all thong tin
                break;
            case 2: // thuc hien thao tac chinh sua
                break;
            default: 
                printf( " Ban da chon nham option, vui long chon lai!\n *********************\n");
                option=3;
                break;
        }
    } while (option==3);


}
void if_bn(bn*infor_bn,vc*infor_vc) // chi thuc hien hien thi
{

}


//  điều kiện nếu bệnh nhân, bác sĩ, vaccin có đầu vào không thỏa mãn
//

//3