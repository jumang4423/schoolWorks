#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_FACE  6
#define NUM_OF_SHAKE 12000

int GetCurrentFace(void);
void PrintFaceCounter(int);

int main()
{
  int FaceIndex, i;
  int Face[6] = {0,0,0,0,0,0};
  /* サイコロの試行と集計 */
  for (i=1; i<=NUM_OF_SHAKE; i++){
    FaceIndex = GetCurrentFace();
    Face[FaceIndex-1]++;
  }
  /* ヒストグラムの表示 */
  for (i=1; i<=NUM_OF_FACE; i++){
    printf("Face[%d]", i);
    PrintFaceCounter(Face[i-1]);
    printf("\n");
  }
  return 0;
}

/* サイコロの面を返す　*/
int GetCurrentFace(void)
{
  int FaceValue;

  /* 剰余算により 1からNUM_OF_FACEの乱数を得る */
  FaceValue = rand() % NUM_OF_FACE + 1;
  return FaceValue;
}

/* 回数を入力としてヒストグラムを表示する　*/
void PrintFaceCounter(int Count)
{
  int i;
  int Height;

  /* 100回未満を切り捨て */
  Height = Count/100;
  for (i=1;i<=Height;i++){
    printf("*");
  }
}
