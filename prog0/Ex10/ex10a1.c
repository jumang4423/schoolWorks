#include<stdio.h>
#define i 10
#define j 10

int main()
{
  /* 入力と入力データの表示 */
  
  int a, b, gyo, retsu;
   int matrix[i][j],t_matrix[i][j];
  scanf("%d%d", &gyo, &retsu);
  printf("行数:%d, 列数:%d\n", gyo, retsu);

  for(a=0;a<gyo;a++)
    {
      for(b=0;b<retsu;b++)
	{
	  scanf("%d", &matrix[a][b]);
	}
    }
    for(a=0;a<gyo;a++)
    {
      for(b=0;b<retsu;b++)
	{
	  printf("%d ", matrix[a][b]);
	}
      printf("\n");
    }
  /* 転置処理 */

    printf("転置後行数:%d, 列数:%d\n", retsu, gyo);
    for(a=0;a<retsu;a++)
    {
      for(b=0;b<gyo;b++)
	{
	  t_matrix[a][b]=matrix[b][a];
	}
    }  
  /* 表示 */

    for(a=0;a<retsu;a++)
    {
      for(b=0;b<gyo;b++)
	{
	  printf("%d ", t_matrix[a][b]);
	}
      printf("\n");
    }
  
  
  return 0;
}
