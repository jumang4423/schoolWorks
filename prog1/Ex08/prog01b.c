#include<stdio.h>

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

int main()
{
    Record data[2]={{1270174, "Ryoma Okuda", 100, 'A' },{1270500, "Hanako Aizu", 99, 'B' }};

    printf("値渡し\n");
    PrintData1(data[0]);
    PrintData1(data[1]);
    printf("ポインタ（アドレス）渡し\n");
    PrintData2(&data[0]);
    PrintData2(&data[1]);
    return 0;
}