#include <stdio.h>

int main() {
  int input;
  int count = 0;
  while (1){
  printf("偶数は%d回入力されています。正の整数を入力してください。\n",count);
  scanf("%d", &input);
  if(input%2==0) count++;
  if(count==2) break;
  }
  printf("２回偶数が入力されました。プログラムを終了します。\n");
  return 0;

}
