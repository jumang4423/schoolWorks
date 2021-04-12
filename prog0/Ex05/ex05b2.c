#include<stdio.h>

int main()
{
  int n;

  printf("０でない自然数ｎを入力してください。\n");
  scanf("%d", &n);

  while(n!=1){
  if(n%2==0){
    n /=2;
  }
  else if(n%2==1){
    n= n*3 +1;
  }
  printf("n = %d\n",n);
  }

printf("終了\n");
  return 0;
}
