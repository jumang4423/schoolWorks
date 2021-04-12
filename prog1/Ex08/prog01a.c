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
    Record member1={1270174, "Ryoma Okuda", 100, 'A' }, 
    member2={1270500, "Hanako Aizu", 99, 'B' };

    printf("値渡し\n");
    PrintData1(member1);
    PrintData1(member2);
    printf("ポインタ（アドレス）渡し\n");
    PrintData2(&member1);
    PrintData2(&member2);
    return 0;
}