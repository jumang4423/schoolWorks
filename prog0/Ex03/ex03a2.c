#include <stdio.h>
int main()
{
  double x = 31.4;
  int i = 29;

  printf("認定単位数は%05dです\n", i);
  printf("認定単位数は%5dです\n", i);
  printf("認定単位数は%-5dです\n", i);
  printf("認定単位数は%+5dです\n", i);
  printf("総合点数は%.3f点です\n", x);
  printf("総合点数は%.6f点です\n", x);
  printf("総合点数は%.6le点です\n", x);
  printf("総合点数は%.3lE点です\n", x); 

  return 0;  
}
