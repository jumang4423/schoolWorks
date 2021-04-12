#include<stdio.h>

#define N 20

typedef struct{
  int  id;       /* ID    */
  char name[20]; /* 名前   */
  int score;    /* 点数　*/
  char grade;   /* 成績 */
} Record;

void PrintData1(Record data)
{
    printf("%d\t%s %d %c\n", data.id, data.name, data.score, data.grade);
}

void PrintData2(Record *p)
{
    printf("%d\t%s %d %c\n", (*p).id, (*p).name, (*p).score, (*p).grade);
}

int InputData(Record *c)
{
    int stat;
    stat = scanf("%d %s %d %c", &(*c).id, (*c).name, &(*c).score, &(*c).grade);
    return stat;
}

int main()
{
    Record data[N];
    int cnt, i=0, j=0, stat;


    while(1)
    {
        stat = InputData(&data[i]);
        if(stat==EOF) break;
        i++;
    }


    printf("値渡し\n");
    for(int j=0; j<i; j++) PrintData1(data[j]);
    printf("ポインタ（アドレス）渡し\n");
    for(int j=0; j<i; j++) PrintData2(&data[j]);
    return 0;
}