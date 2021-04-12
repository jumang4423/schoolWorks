#include<stdio.h>
#include"prog01.h"

#define YEAR 2019
#define MONTH 10
#define DAY 1

Record input(void);
void output(Record);
int getage(Record);


int main()
{
    Record data[2];
    printf("--------データ入力--------\n");

    for(int i=0; i<2; i++)
    {
        printf("%d人目のデータを入力して下さい\n", i +1);
        data[i] = input();
        printf("\n");
    }
    printf("--------データ出力--------\n");
    printf("年齢基準日：%d年%d月%d日\n", YEAR, MONTH, DAY);
    for(int i=0; i<2; i++)
    {
        printf("%d人目のデータ:\n", i+1);
        output(data[i]);
        printf("年齢：%d", getage(data[i]));
        printf("\n");
    }


    return 0;
}

Record input(void)
{
    Record data;
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
    return data;
}

void output(Record data)
{
    printf("名前(姓): %s\n", data.familyname);
    printf("名前(名): %s\n", data.firstname); 
    printf("生年月日: %d年 %d月%d日 (", data.birthday[0], data.birthday[1], data.birthday[2]);
    if(data.gender==0) printf("男性)\n");
    else printf("女性)\n");
}

int getage(Record data)
{
    int age;
    age = YEAR - data.birthday[0];
    if(data.birthday[1]>= MONTH)
    {
        if(data.birthday[2]> DAY) age--;
    }
    return age;
}