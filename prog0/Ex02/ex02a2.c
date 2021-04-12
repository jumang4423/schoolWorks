#include <stdio.h>

int main()
{
  int i, j, k;
  
  printf("縦の流長さを入力してください\n");
  scanf("%d",&i);

    printf("横の流長さを入力してください\n");
    scanf("%d",&j);

    printf("高さの流長さを入力してください\n");
    scanf("%d",&k);

  printf("体積：%d\n", i*j*k);
  printf("表面積：%d\n", i*j*2+i*k*2+j*k*2);

  return 0;

}
