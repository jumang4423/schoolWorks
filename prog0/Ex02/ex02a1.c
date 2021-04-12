#include <stdio.h>

int main()
{
  int a;
  printf("整数値を入力してください:");

  scanf ("%d", &a);

  printf("入力された値は%dで、５で割った余りは%dです。\n", a, a%5);

  return 0;

}
