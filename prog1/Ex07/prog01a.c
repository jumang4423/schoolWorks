#include<stdio.h>

struct record {      /* 個人レコード                          */
  char familyname[20];     /* 名前(姓)*/
  char firstname[20];      /* 名前(名)*/
  int  birthday[3];  /* 誕生日（要素0:西暦 要素1:月 要素2:日）*/
  int  gender;       /* 性別 (0:男性, 1:女性)                 */
};

int main()
{

    struct record data;
    int stat;
    printf("データを入力して下さい\n");
    //
    printf("名前（姓）        ->");
    scanf("%s", data.familyname);
    //
    printf("名前（名）        ->");
    scanf("%s", data.firstname);
    //
    printf("生まれた年（西暦） ->");
    scanf("%d", &data.birthday[0]);
    //
    printf("生まれた月        ->");
    scanf("%d", &data.birthday[1]);
    //
    printf("生まれた日        ->");
    scanf("%d", &data.birthday[2]);
    //
    printf("性別(0:男性,1:女性) ->");
    scanf("%d", &data.gender);
    printf("\n");
    ////
    printf("名前(姓): %s\n", data.familyname);
    printf("名前(名): %s\n", data.firstname); 
    printf("生年月日: %d年 %d月%d日 (", data.birthday[0], data.birthday[1], data.birthday[2]);
    if(data.gender==0) printf("男性)\n");
    else printf("女性)\n");
    return 0;
}