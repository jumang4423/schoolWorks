#include<stdio.h>
#include"prog01.h"
#define N 20

#define YEAR 2019
#define MONTH 10
#define DAY 1

Record input(void);
void output(Record);
int getage(Record);

int main()
{
    Record data[N];
    int i, j;
    for(i = 0; i<N; i++)
    {
        data[i] = input();
        if(data[i].gender==-1) break;
    }
    printf("--------データ出力--------\n");
    printf("年齢基準日：%d年%d月%d日\n", YEAR, MONTH, DAY);
    for(j = 0; j<i; j++)
    {
        printf("%d人目:", j + 1);
        output(data[j]);
    }
    return 0;
}




Record input(void)
{
    Record data;
    int f_stat;
    if((f_stat = scanf("%s", data.familyname)) == EOF) data.gender=-1;
    scanf("%s", data.firstname);
    scanf("%d", &data.birthday[0]);
    scanf("%d", &data.birthday[1]);
    scanf("%d", &data.birthday[2]);
    scanf("%d", &data.gender);
    return data;
}

void output(Record data)
{
    printf("名前(姓): %s", data.familyname);
    printf(" %s ", data.firstname); 
    printf(" %d年 %d月%d日生 ", data.birthday[0], data.birthday[1], data.birthday[2]);
    printf("年齢：%d ", getage(data));
    if(data.gender==0) printf("男性\n");
    else printf("女性\n");
    
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