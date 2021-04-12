#include <stdio.h>

int main() {

  int n, m, count = 0;
  printf("初期の入力：");
  scanf("%d", &n);
  while(n>0){
    count++;
    n/=2;
    m= n%2;
    printf("%d回目のループ　商%d　あまり%d　\n", count, n, m);

  }
  return 0;
}
