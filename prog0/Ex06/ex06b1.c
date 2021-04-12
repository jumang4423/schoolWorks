#include <stdio.h>

int main()
{
  int data, i=0;
  printf("整数を入力してください：");
  scanf("%d", &data);
  for(i=0;i<=data;i++){
    if(i%3==1){
      printf("%d\n", i);
    }
  }
  return 0;
}
